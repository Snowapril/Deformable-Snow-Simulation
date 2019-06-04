/**
 * @file ToonFilesystem.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief cross platform file system class for this engine.
 * @version 0.1
 * @date 2019-05-25
 * 
 * @copyright Copyright (c) 2019
 */
#ifndef TOON_FILESYSTEM_H
#define TOON_FILESYSTEM_H

#include "ToonHeaderPrefix.h"

#include <ToonSingleton.h>
#include <string>
#include <unordered_map>
#include <filesystem>

namespace Toon
{
	/****************************************************************************
						Filesystem class declaration
	****************************************************************************/

	/**
	 * @brief cross platform file system class.
	 * 
	 * provide several useful methods for dealing with file system of client's operating system.
	 */
	class Filesystem : public Common::Singleton<Filesystem>
	{
	private:
		std::unordered_map< std::string, std::string > dirTable;
		std::string rootPath;
	public:
		/**
		 * @brief construct file system with given root directory path. 
		 * 
		 * @param rootPath path string of root directory.
		 */
		Filesystem( std::string const & rootPath );
		~Filesystem();

		/**
		 * @brief set the label of directory path. 
		 * 
		 * \code{.cpp}
		 * Filesystem fs("C:/Users/reDesktop/ToonEngine");
		 * fs.setDirectory("resource", "./Data/Resource");
		 * \endcode
		 * 
		 * @param label 
		 * @param directory 
		 */
		void		setDirectory	( std::string const & label, std::string const & directory );
		/**
		 * @brief return the assigned root path directory.
		 * 
		 * @return std::string root directory 
		 */
		std::string getRootPath		( void ) const;
		/**
		 * @brief return the absolute path of directory which  given label name.
		 * 
		 * @param filename 
		 * @return std::string 
		 */
		std::string getAbsolutePath	( std::string const & filename ) const;
	public:
		/**
		 * @brief return whether if given relative path exists or not.
		 * 
		 * @param relativePath 
		 * @param s 
		 * @return true if given relative path exists.
		 * @return false if given relative path doesn't exists.
		 */
		bool isExists(std::string const& relativePath, std::filesystem::file_status s = std::filesystem::file_status{}) const;
		/**
		 * @brief 	creates directory which will be located at given relative path.
		 * 
		 * @param relativePath 
		 */
		void createDirectory(std::string const & relativePath) const;
	};
};

#include "ToonHeaderPostfix.h"

#endif //FILE_SYSTEM_H