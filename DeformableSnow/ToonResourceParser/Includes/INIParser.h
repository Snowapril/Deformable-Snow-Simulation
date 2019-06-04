/**
 * @file INIParser.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief provide single class for parsing ini config file.
 * @details
 * @version 0.1
 * @date 2019-05-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef INI_PARSER_H
#define INI_PARSER_H

#include <unordered_map>
#include <optional>
#include <string>
#include <cassert>
#include <fstream>
#include <filesystem>
#include <iostream>

namespace ToonResourceParser
{
	/**
	 * @brief parse ini file and useful getter methods for casting parsed string to what user want type.
	 * 
	 * when user initialize the instance with 'open' method or constructor with std::string parameter,
	 * this class instance have whole ini sections and variables.
	 * Before class instance is deleted, user can optain a value at anytime with a string which mixed section name and variable name.
	 * 
	 * Usage example.
	 * \code{.cpp}
	 * INIParser parser;
	 * bool result = parser.open("example.ini");
	 * if (result == false) // code for failed case.
	 * auto val_str = parser.get<std::string>("section.varname");
	 * if (!val_str) // code for failed case that given section name and variable name don't exist in ini file.
	 * std::string str = val_str.value();
	 * auto val_int = parser.get<int>("section2.varname2");
	 * if (!val_int) // code for failed case that given section name and variable name don't exist in ini file.
	 * int i = val_int.value();
	 * \endcode
	 * 
	 */
	class INIParser
	{
	private:
		class INISection
		{
		public:
			using storage_t = std::unordered_map<std::string, std::string>;
			INISection() = default;
			/**
			 * @brief add variable name and value to ini section.
			 * 
			 * @param name ini-variable name 
			 * @param data ini-variable value
			 */
			void addData(std::string const& name, std::string const& data) noexcept
			{
				storage.insert(std::make_pair(name, data));
			}
			/**
			 * @brief return string which represents actual value with given variable name.
			 * 
			 * @param name ini-variable name 
			 * @return std::optional<std::string> 
			 */
			std::optional<std::string> getData(std::string const& name) const noexcept
			{
				auto iter = storage.find(name);

				if (iter == end(storage)) return {};
				else					  return iter->second;
			}
		private:
			storage_t storage{};
		};
	public:
		using storage_t = std::unordered_map<std::string, INISection>;

		INIParser() = default;
		/**
		 * @brief open ini file with given path. when failed, print error log and terminate the program.
		 * 
		 * @param ini file path that user wants to parse.
		 */
		INIParser(std::string const& path)
		{
			namespace fs = std::filesystem;

			if (!open(path))
			{
				std::cerr << "Cannot find path with [ " << fs::absolute(path) << " ] " << std::endl;
				std::terminate();
			}
		}
		/**
		 * @brief open ini file with given path and parse whole ini-sections and store them to hash-table. 
		 * 
		 * @param path ini file path that user want to parse.
		 * @return true   if the file with given path exists and parsing is successful (there is no incorrect contents which violate ini file format grammar).
		 * @return false  if the file with given path doesn't exist or parsing is failed (there is incorrect contents which violate ini file format grammar).
		 */
		bool open(std::string const& path) noexcept
		{
			std::ifstream iniFile(path);
			if (iniFile.is_open() == false) return false;

			INISection section;
			std::string sectionName{};
			std::string line{};

			while (std::getline(iniFile, line))
			{
				if (line.empty()) continue;

				if (line.find('[') == 0) // check whether if the given line is section name or not.
				{
					if (!sectionName.empty())
					{
						storage[sectionName] = section;
						section = INISection();
					}
					sectionName = line.substr(1, line.length() - 2);
				}
				else // otherwise, given line will be variable name and value enclosed to section name.
				{
					auto equalLoc = line.find('=');
					if (equalLoc == std::string::npos)
					{
						iniFile.close();
						return false;
					}
					std::string name = line.substr(0, equalLoc);
					std::string data = line.substr(equalLoc + 1);

					name.erase(std::remove_if(begin(name), end(name), ::isspace), end(name)); // remove blank space in the name.

					section.addData(name, data);
				}
			} // end of file

			if (!sectionName.empty()) storage[sectionName] = section;
			iniFile.close();
			return true;
		}

		/**
		 * @brief get the actual value with a given string which mixed section name and variable name.
		 * 
		 * this is failed case of parsing.
		 * this is the case that given template parameter is wrong type (given type mismatched with string, int, double, bool) 
		 * 
		 * @tparam Type the type what user want to get
		 * @param name the ini-variable name what user want to get
		 * @return std::optional<Type> 
		 */
		template <typename Type>
		std::optional<Type> getData(std::string const& name) const noexcept
		{
			return {};
		}
		/**
		 * @brief get the actual integer value with a given string which mixed section name and variable name.
		 * 
		 * @tparam  integer type specialization
		 * @param name the ini-variable name what user want to get
		 * @return std::optional<int> 
		 */
		template <>
		std::optional<int> getData(std::string const& name) const noexcept
		{
			auto originalData = getOriginalData(name);
			if (!originalData) return {};
			std::string strData = originalData.value();
			strData.erase(std::remove_if(begin(strData), end(strData), ::isspace), end(strData)); // remove blank space in the name.
			return std::stoi(strData);
		}
		/**
		 * @brief get the actual string value with a given string which mixed section name and variable name.
		 * 
		 * @tparam  string type specialization
		 * @param name the ini-variable name what user want to get
		 * @return std::optional<std::string> 
		 */
		template <>
		std::optional<std::string> getData(std::string const& name) const noexcept
		{
			auto originalData = getOriginalData(name);
			if (!originalData) return {};
			std::string stringData = originalData.value();
			auto firstQuotesLoc = stringData.find_first_of('"');
			auto secondQuotesLoc = stringData.find_last_of('"');
			return stringData.substr(firstQuotesLoc + 1, secondQuotesLoc - firstQuotesLoc - 1);
		}
		/**
		 * @brief get the actual floating-point value with a given string which mixed section name and variable name.
		 * 
		 * @tparam  double type specialization
		 * @param name the ini-variable name what user want to get
		 * @return std::optional<double> 
		 */
		template <>
		std::optional<double> getData(std::string const& name) const noexcept
		{
			auto originalData = getOriginalData(name);
			if (!originalData) return {};
			std::string strData = originalData.value();
			strData.erase(std::remove_if(begin(strData), end(strData), ::isspace), end(strData)); // remove blank space in the name.
			return std::stod(strData);
		}
		/**
		 * @brief get the actual boolean value with a given string which mixed section name and variable name.
		 * 
		 * @tparam  bool type specialization
		 * @param name the ini-variable name what user want to get
		 * @return std::optional<bool> 
		 */
		template <>
		std::optional<bool> getData(std::string const& name) const noexcept
		{
			auto originalData = getOriginalData(name);
			if (!originalData) return {};
			std::string boolString = originalData.value();
			boolString.erase(std::remove_if(begin(boolString), end(boolString), ::isspace), end(boolString)); // remove blank space in the name.
			return boolString == "true" || boolString == "TRUE";
		}
		private:
		/**
		 * @brief get the string which represents the actual value with a given string which mixed section name and variable name
		 * 
		 * @param name string which mixed section name and variable name.
		 * @return std::optional<std::string> 
		 */
		std::optional<std::string> getOriginalData(std::string const & name) const noexcept
		{
			auto offset = name.find_first_of('.');
			std::string secName = name.substr(0, offset);  // split section  name from whole input string
			std::string varName = name.substr(offset + 1); // split variable name from whole input string
				
			auto iter = storage.find(secName);
			if (iter == end(storage)) return {};

			auto const& section = iter->second;
			auto tempData = section.getData(varName);

			if (!tempData) return {};

			std::string stringData = tempData.value();
			return stringData;
		}
	private:
		storage_t storage{};
	};
};

#endif