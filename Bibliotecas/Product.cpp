#include "Product.h"
#include "iostream"
#include "string.h"
#include "SystemData.h"

Product::Product()
{
	SetStatus(0);
	SetPreference(0);
	SetValidity(0);
}

Product::~Product()
{
	SetStatus(0);
}

void Product::SetName_(char NewName_[])
{
	strcpy_s(Name_, 20, NewName_);
}

void Product::SetValidityDay(int NewValidityDay)
{
	ValidityDay = NewValidityDay;
}

void Product::SetValidityMonth(int NewValidityMonth)
{
	ValidityMonth = NewValidityMonth;
}

void Product::SetValidityYear(int NewValidityYear)
{
	ValidityYear = NewValidityYear;
}

void Product::SetAmount(int NewAmount)
{
	Amount = NewAmount;
}

void Product::SetValidity(int NewValidity)
{
	Validity = NewValidity;
}

void Product::SetOwner_(char NewOwner_[20])
{
	strcpy_s(Owner_, 20, NewOwner_);
}

void Product::SetPreference(int NewPreference)
{
	Preference = NewPreference;
}

void Product::SetStatus(int NewStatus)
{
	Status = NewStatus;
}

void Product::GetName_(char Name_[])
{
	strcpy_s(Name_, 20, this->Name_);
}

int Product::GetValidityDay()
{
	return(ValidityDay);
}

int Product::GetValidityMonth()
{
	return(ValidityMonth);
}

int Product::GetValidityYear()
{
	return(ValidityYear);
}

int Product::GetAmount()
{
	return(Amount);
}

void Product::GetOwner_(char Owner_[])
{
	strcpy_s(Owner_, 20, this->Owner_);
}

int Product::GetPreference()
{
	return(Preference);
}

int Product::GetValidityTotalDays()
{
	return(ValidityTotalDays);
}

int Product::GetValidity()
{
	return(Validity);
}

int Product::GetStatus()
{
	return(Status);
}

void Product::CalculateValidityTotalDays()
{
	int CurrentDay = GetCurrentDay();
	int CurrentMonth = GetCurrentMonth() * 30;
	int CurrentYear = (GetCurrentYear() - 2000) * 365;
	int CurrentTotalDays = CurrentDay + CurrentMonth + CurrentYear;
	ValidityTotalDays = ValidityDay + ValidityMonth * 30 + (ValidityYear - 2000) * 365;
	ValidityTotalDays = CurrentTotalDays - ValidityTotalDays;
}