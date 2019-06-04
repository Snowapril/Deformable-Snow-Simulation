#include "stdafx.h"
#include "ToonTimer.h"
#include "ToonLogger.h"

namespace Common
{
	template <> Toon::Timer* Singleton<Toon::Timer>::instance = nullptr;
}

namespace Toon
{
	/****************************************************************************
						Timer class definition
	*********************************************************************** *****/
	Timer::~Timer()
	{
		Logger::getConstInstance().infoMessage( "[Singleton] {0:>40} ({1:p})", "Timer instance is released", reinterpret_cast<void*>(instance));
	}
	void Timer::tick(void) noexcept
	{
		using namespace std::chrono;

		auto previousTime = currentTime;
		currentTime = high_resolution_clock::now();
		auto elapsedTime = duration_cast< duration<double> >( currentTime - previousTime ).count();

		if (bPaused)
		{
			pausedTime += elapsedTime;
			deltaTime = 0.0;
		}
		else
		{
			deltaTime = elapsedTime;
		}

		if (deltaTime < 0.0) deltaTime = 0.0;
	}

	void Timer::start(void) noexcept
	{
		if (bPaused) bPaused = false;
	}

	void Timer::reset(void) noexcept
	{
		startTime	= ( currentTime = std::chrono::high_resolution_clock::now() );
		bPaused		= false	;
		deltaTime	= 0.0	;
		pausedTime	= 0.0	;
	}

	void Timer::pause(void) noexcept
	{
		if (!bPaused) bPaused = true;
	}

	bool Timer::isOnGoing(void) const noexcept
	{
		return !bPaused;
	}

	bool Timer::isPaused(void) const noexcept
	{
		return  bPaused;
	}

	float Timer::getDeltaTime(void) const noexcept
	{
		return static_cast<float>(deltaTime);
	}

	float Timer::getTotalTime(void) const noexcept
	{
		using namespace std::chrono;
		auto wholeDuration = duration_cast< duration<double> >( currentTime - startTime ).count();

		return static_cast<float>( wholeDuration - pausedTime );
	}
};