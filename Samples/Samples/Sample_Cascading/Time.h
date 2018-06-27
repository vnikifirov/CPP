#pragma once

// Class interface
class Time
{
public:
	Time(int = 0, int = 0, int = 0);
	Time &setHour(int);
	Time &setMinute(int);
	Time &setSecond(int);

private:
	int hour;
	int minute;
	int second;
};