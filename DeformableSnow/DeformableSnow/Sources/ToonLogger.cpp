#include "stdafx.h"
#include "ToonLogger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>
#include "ToonFilesystem.h"

namespace Common
{
	template <> Toon::Logger* Singleton<Toon::Logger>::instance = nullptr;
}

namespace Toon
{
	/****************************************************************************
						Logger class definition
	****************************************************************************/

	Logger::Logger(std::string const& logDirectory)
	{
		auto& fs = Filesystem::getConstInstance();
		if (!fs.isExists(logDirectory))
		{
			fs.createDirectory(logDirectory);
		}

		spdlog::init_thread_pool(8192, 2);
#ifdef _DEBUG
		auto stdoutSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		auto fileSink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(fs.getAbsolutePath(logDirectory) + std::string("/engine.log"), 1048576 * 3, 2);
		std::vector<spdlog::sink_ptr> sinks{ stdoutSink, fileSink };
#else
		auto fileSink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(fs.getAbsolutePath(logDirectory) + std::string("/engine.log"), 1048576 * 3, 2);
		std::vector<spdlog::sink_ptr> sinks{ fileSink };
#endif
		logger = std::make_shared<spdlog::async_logger>("logger", begin(sinks), end(sinks), spdlog::thread_pool(), spdlog::async_overflow_policy::overrun_oldest);
		logger->set_level(spdlog::level::trace);

		using namespace std::chrono_literals;
		spdlog::register_logger(logger);
	}

	Logger::~Logger()
	{
		Logger::getConstInstance().infoMessage("[Singleton] {0:>40} ({1:p})", "Logger instance is released", reinterpret_cast<void*>(instance));
		spdlog::shutdown();
		logger.reset();
	}
};