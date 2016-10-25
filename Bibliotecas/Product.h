#pragma once
#include "SystemData.h"
#include "User.h"

class Product :
	public SystemData,
	public User
{
private:
	char Name_[20];
	int ValidityDay;
	int ValidityMonth;
	int ValidityYear;
	int ValidityTotalDays;
	int Amount;
	char Owner_[20];
	int Preference;
	int Status;
	int Validity;
public:
	Product();
	~Product();
	void SetName_(char NewName_[]);
	void SetValidityDay(int NewValidityDay);
	void SetValidityMonth(int NewValidityMonth);
	void SetValidityYear(int NewValidityYear);
	void SetAmount(int NewAmount);
	void SetOwner_(char NewOwner_[]);
	void SetPreference(int NewPreference);
	void SetStatus(int NewStatus);
	void SetValidity(int NewValidity);
	void GetName_(char Name_[]);
	int GetValidityDay();
	int GetValidityMonth();
	int GetValidityYear();
	int GetValidity();
	int GetAmount();
	void GetOwner_(char Owner_[]);
	int GetPreference();
	int GetValidityTotalDays();
	int GetStatus();
private:
	void CalculateValidityTotalDays();
};