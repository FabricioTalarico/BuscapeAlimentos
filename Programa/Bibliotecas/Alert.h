#pragma once
class Alert
{
private:
	int ShowAlert;
	char Description[200];
public:
	Alert();
	~Alert();
	void SetShowAlert(int NewShowAlert);
	void SetDescription(char NewDescription[]);
	int GetShowAlert();
	void ShowAlertMessage();
};