#include "SystemData.h"
#include "iostream"
#include <ctime>

using namespace std;

SystemData::SystemData()
{
	time_t RawTime;
	struct tm * TimeInfo;
	time(&RawTime);
	TimeInfo = localtime(&RawTime);
	CurrentDay = TimeInfo->tm_mday;
	CurrentMonth = TimeInfo->tm_mon + 1;
	CurrentYear = TimeInfo->tm_year + 1900;
}

SystemData::~SystemData()
{

}

void SystemData::UpdateHours()
{
	time_t RawTime;
	struct tm * TimeInfo;
	time(&RawTime);
	TimeInfo = localtime(&RawTime);
	CurrentSecond = TimeInfo->tm_sec;
	CurrentMinute = TimeInfo->tm_min;
	CurrentHour = TimeInfo->tm_hour;
}

int SystemData::GetCurrentDay()
{
	return(CurrentDay);
}

int SystemData::GetCurrentMonth()
{
	return(CurrentMonth);
}

int SystemData::GetCurrentYear()
{
	return(CurrentYear);
}

int SystemData::GetCurrentSecond()
{
	return(CurrentSecond);
}

int SystemData::GetCurrentMinute()
{
	return(CurrentMinute);
}

int SystemData::GetCurrentHour()
{
	return(CurrentHour);
}

void SystemData::ShowCurrentDay()
{
	cout << "Hoje: ";
	if (CurrentDay < 10)
	{
		cout << "0";
	}
	cout << CurrentDay << '/';
	if (CurrentMonth < 10)
	{
		cout << "0";
	}
	cout << CurrentMonth << '/' << CurrentYear << endl;
}