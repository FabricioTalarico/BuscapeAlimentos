#pragma once
class User
{
private:
	char Nick[20];
	char Password[15];
	int Status;
public:
	User();
	User(char NewNick[], char NewPassword[]);
	~User();
	void SetNick(char NewNick[]);
	void SetPassword(char NewPassword[]);
	void SetStatus(int NewStatus);
	void GetNick(char Nick[]);
	void GetPassword(char Password[]);
	int GetStatus();
	int CompareNick(char Nick[]);
	int ComparePassword(char Password[]);
};

