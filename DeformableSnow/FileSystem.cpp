#include "FileSystem.hpp"
#include "Logger.hpp"
#include "Obfuscator.hpp"

std::shared_ptr<FileSystem> Singleton<FileSystem>::instance(new FileSystem());

void FileSystem::setRootPath(std::string path) {
	rootPath = path;
}

void FileSystem::addTable(std::string key, std::string value) {
	table[key] = value;
}

std::string FileSystem::getFullPath(std::string key, std::string path) {
	auto iter = table.find(key);

	if (iter == table.end()) {
		ERROR_LOG(OBFUSCATE("key [{}] doesn't exists in path table."), key);
		return std::string();
	}

	return rootPath + table[key] + path;
}