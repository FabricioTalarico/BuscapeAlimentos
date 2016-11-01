#pragma once

class SystemData
{
private:
	int CurrentDay;
	int CurrentMonth;
	int CurrentYear;
	int CurrentSecond;
	int CurrentMinute;
	int CurrentHour;
public:
	SystemData();
	~SystemData();
	void UpdateHours();
	int GetCurrentDay();
	int GetCurrentMonth();
	int GetCurrentYear();
	int GetCurrentSecond();
	int GetCurrentMinute();
	int GetCurrentHour();
	void ShowCurrentDay();
};