#include "Time.h"

// The implementation:

Time &Time::setHour(int h)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	return *this;
}


Time &Time::setMinute(int m)
{
	minute = (m >= 0 && m < 60) ? m : 0;
	return *this;
}


Time &Time::setSecond(int s)
{
	second = (s >= 0 && s < 60) ? s : 0;
	return *this;
}
