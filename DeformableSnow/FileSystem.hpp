#ifndef FILE_SYSTEM_HPP
#define FILE_SYSTEM_HPP

#include <string>
#include <unordered_map>
#include "Singleton.hpp"

class FileSystem : public Singleton<FileSystem> {
	using path_table = std::unordered_map<std::string, std::string>;
public:
	void setRootPath(std::string path);
	void addTable(std::string key, std::string value);
	std::string getFullPath(std::string key, std::string path);
private:
	std::string rootPath;
	path_table table;
};


#endif //FILE_SYSTEM_HPP