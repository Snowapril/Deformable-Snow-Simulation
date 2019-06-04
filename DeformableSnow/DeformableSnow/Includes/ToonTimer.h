/**
 * @file ToonTimer.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief cross platform timer class for the toon engine.
 * @version 0.1
 * @date 2019-05-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_TIMER_H
#define TOON_TIMER_H

#include "ToonHeaderPrefix.h"

#include <ToonSingleton.h>
#include <chrono>

namespace Toon
{
	/****************************************************************************
						Timer class declaration
	****************************************************************************/
	using time_point_t = std::chrono::time_point< std::chrono::high_resolution_clock >;

	/**
	 * @brief cross platform timer class for the toon engine.
	 * 
	 */
	class Timer : public Common::Singleton< Timer >
	{
	private:
		time_point_t	startTime	{};
		time_point_t	currentTime {};
		double			pausedTime	= 0.0;  // represent elapsed time with state "pause"
		double			deltaTime	= 0.0;
		bool			bPaused		= false;
	public:
		Timer() = default;
		~Timer();

		/**
		 * @brief tick the timer. this method must be called every single frame. 
		 */
		void tick	(void) noexcept;
		/**
		 * @brief start the timer.
		 * 
		 */
		void start	(void) noexcept;
		/**
		 * @brief reset the timer
		 * 
		 */
		void reset	(void) noexcept;
		/**
		 * @brief pause the timer.
		 * 
		 */
		void pause	(void) noexcept;

		/**
		 * @brief return whether if the timer is ongoing or not
		 * 
		 * @return true  if timer is on going
		 * @return false if timer is paused.
		 */
		bool isOnGoing	(void) const noexcept;
		/**
		 * @brief return whether if the timer is ongoing or not
		 * 
		 * @return true if timer is paused.
		 * @return false  if timer is on going
		 */
		bool isPaused	(void) const noexcept;

		/**
		 * @brief Get the Delta Time of the timer.
		 * 
		 * @return float 
		 */
		float getDeltaTime(void) const noexcept;
		/**
		 * @brief Get the Total Time of the timer.
		 * 
		 * @return float 
		 */
		float getTotalTime(void) const noexcept;
	};
};

#include "ToonHeaderPostfix.h"

#endif