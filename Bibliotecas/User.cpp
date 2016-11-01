#include "User.h"
#include "iostream"
#include "string.h"

User::User()
{
	SetStatus(0);
}

User::User(char NewNick[], char NewPassword[])
{
	SetNick(NewNick);
	SetPassword(NewPassword);
	SetStatus(1);
}

User::~User()
{

}

void User::SetNick(char NewNick[])
{
	strcpy_s(Nick, 20, NewNick);
}

void User::SetPassword(char NewPassword[])
{
	strcpy_s(Password, 20, NewPassword);
}

void User::SetStatus(int NewStatus)
{
	Status = NewStatus;
}

void User::GetNick(char Nick[])
{
	strcpy_s(Nick, 20, this->Nick);
}

void User::GetPassword(char Password[])
{
	strcpy_s(Password, 20, this->Password);
}

int User::GetStatus()
{
	return (Status);
}

int User::CompareNick(char Nick[])
{
	return(strcmp(Nick, this->Nick));
}

int User::ComparePassword(char Password[])
{
	return(strcmp(Password, this->Password));
}