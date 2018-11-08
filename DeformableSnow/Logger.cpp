#include "Logger.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

std::shared_ptr<Logger> Singleton<Logger>::instance(new Logger());

void Logger::initLogger(spdlog::level::level_enum logLevel) {
	auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	console = std::make_shared<spdlog::logger>("setup", sink);
	console->set_level(logLevel);
}

std::shared_ptr<spdlog::logger> const Logger::getConsole() const {
	return console;
}
