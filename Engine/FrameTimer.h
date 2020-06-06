#pragma once
#include <chrono>

class FrameTimer
{
public:
	FrameTimer()
	{
		last = std::chrono::steady_clock::now();
	}
	void Mark()
	{
		const auto old = last;
		last = std::chrono::steady_clock::now();
		dur = old - last;
	}
	float Duration()
	{
		return dur.count();
	}
private:
	std::chrono::steady_clock::time_point last;
	std::chrono::steady_clock::duration dur;
};

