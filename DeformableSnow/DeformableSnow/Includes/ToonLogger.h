/**
 * @file ToonLogger.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief logging system class 
 * @version 0.1
 * @date 2019-05-25 
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_LOGGER_H
#define TOON_LOGGER_H

#include "ToonHeaderPrefix.h"

#pragma warning(push)
#pragma warning( disable :  4244 )
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#pragma warning (pop)

#include <ToonSingleton.h>
#include <string>
#include <memory>

namespace Toon
{
	/****************************************************************************
							Logger class declaration
	****************************************************************************/

	/**
	 * @brief logger class of toon engine.
	 * 
	 */
	class Logger : public Common::Singleton<Logger>
	{
	private:
		std::shared_ptr<spdlog::async_logger> logger;
	public:
		/**
		 * @brief set the directory where log file will be created.
		 * 
		 * @param logDirectory 
		 */
		Logger(std::string const& logDirectory);
		~Logger();

		/**
		 * @brief print logging message with info level.
		 * 
		 * @tparam Args 
		 */
		template < typename... Args >
		void infoMessage (char const*, Args&&... ) const noexcept;
		/**
		 * @brief print logging message with warning level.
		 * 
		 * @tparam Args 
		 */
		template < typename... Args >
		void warnMessage (char const*, Args&&... ) const noexcept;
		/**
		 * @brief print logging message with error level.
		 * 
		 * @tparam Args 
		 */
		template < typename... Args >
		void errorMessage(char const*, Args&&... ) const noexcept;
	};

	/****************************************************************************
						Logger class definition
	****************************************************************************/
	template < typename... Args >
	void Logger::infoMessage(char const* fmt, Args&&... args ) const noexcept
	{
		logger->info( fmt, std::forward<Args>(args)... );
	}

	template < typename... Args >
	void Logger::warnMessage(char const* fmt, Args&&... args ) const noexcept
	{
		logger->warn( fmt, std::forward<Args>(args)... );
	}

	template < typename... Args >
	void Logger::errorMessage(char const* fmt, Args&&... args ) const noexcept
	{
		logger->error( fmt, std::forward<Args>(args)... );
	}
};

#include "ToonHeaderPostfix.h"

#endif