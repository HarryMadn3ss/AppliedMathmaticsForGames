#pragma once

#include <chrono>

using namespace std::chrono;

class Timer
{
private:
	steady_clock::time_point lastFrame; //std::chrono::steady_clock
	steady_clock::time_point firstFrame;
	
	
protected:


public:
	Timer();
	~Timer();

	float GetDeltaTime();
	void Tick();

	float GetAppTime() { return duration<float>(steady_clock::now() - firstFrame).count(); }	

};

