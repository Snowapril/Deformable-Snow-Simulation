#ifndef TOON_TIMER_H
#define TOON_TIMER_H

#include "ToonHeaderPrefix.h"

#include <chrono>

namespace Toon
{
	using time_point_t = std::chrono::time_point< std::chrono::high_resolution_clock >;

	class Timer
	{
	private:
		time_point_t	startTime	{};
		time_point_t	currentTime {};
		double			pausedTime	= 0.0;  // represent elapsed time with state "pause"
		double			deltaTime	= 0.0;
		bool			bPaused		= false;
	public:
		Timer() = default;

		void tick	(void) noexcept;
		void start	(void) noexcept;
		void reset	(void) noexcept;
		void pause	(void) noexcept;

		bool isOnGoing	(void) const noexcept;
		bool isPaused	(void) const noexcept;

		float getDeltaTime(void) const noexcept;
		float getTotalTime(void) const noexcept;
	};
};

#include "ToonHeaderPostfix.h"

#endif