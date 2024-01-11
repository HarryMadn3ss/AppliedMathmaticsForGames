#include "Timer.h"

Timer::Timer()
{
	firstFrame = steady_clock::now();
	lastFrame = steady_clock::now();
}

Timer::~Timer()
{
}

float Timer::GetDeltaTime()
{	
	return duration<float>(steady_clock::now() - lastFrame).count();
}

void Timer::Tick()
{
	lastFrame = steady_clock::now();

}
