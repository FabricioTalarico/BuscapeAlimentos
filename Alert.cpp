#include "Alert.h"
#include "string.h"
#include "iostream"

using namespace std;

Alert::Alert()
{
	SetShowAlert(0);
}

Alert::~Alert()
{

}

void Alert::SetShowAlert(int NewShowAlert)
{
			ShowAlert = NewShowAlert;
}

void Alert::SetDescription(char NewDescription[])
{
	strcpy_s(Description, 200, NewDescription);
}

int Alert::GetShowAlert()
{
	return(ShowAlert);
}

void Alert::ShowAlertMessage()
{
	if (ShowAlert == 1)
	{
		cout << Description;
	}
}