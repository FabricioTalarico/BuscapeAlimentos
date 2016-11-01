#include "iostream"
#include "Alert.h"
#include "Product.h"
#include "ShopList.h"
#include "SystemData.h"
#include "User.h"
#include "string.h"
#include <locale.h>
#include "stdlib.h"
#define MAX 10

using namespace std;

//Protótipos:
int SeeYourProducts(Product Products[], Alert AlertReposition[]);
int AlterProduct(Product Products[], int Opt, Alert AlertReposition[]);
int IncludeProduct(Product Products[], int UserAccount, User Users[]);
int ExcludeProduct(Product Products[], int AutoExclude);
int ShopCar(ShopList ShopLists, Product Products[]);
int AlertPreferences(Alert AlertValidity[], Alert AlertReposition[]);
int InitialVerifier(int Status, Alert Alerts[], int Error);
int InitialVerifier(int Status, Product Products[], int Error);
int InitialVerifier(int Status, ShopList ShopLists,  Product Products[], int Error);
int IncludeUser(User Users[]);
int Suggest(char Name_[]);
void Error(int indice);

//Função Principal:
int main()
{
//Inicialização:
	SystemData System;
	User Users[MAX];
	Alert AlertValidity[MAX];
	Alert AlertReposition[MAX];
	Product Products[MAX];
	ShopList ShopLists;
	setlocale(LC_ALL, "Portuguese");
//Variáveis:
	Users[0].SetNick("Admin");
	Users[0].SetPassword("0000");
	int Option = 0;
	char Nick[20], Password[15];
	int LimitOfChances = 3;
	int LimitSecond = 0;
	int LimitMinute = 0;
	int LimitHour = 0;
	int UserAccount = 0;
	char Description[200] = "!O Produto ";
	char Value[20];
//Menu Pré-Login:
PreLogin:
	cout << "Bem-Vindo!\nInsira o Número da Opção Desejada:\n 1.Fazer Login\n 2.Fazer Cadastro\n\n 0.Fechar Programa\n\n > ";
	cin >> Option;
	switch (Option)
	{
	case 1:
		if (LimitOfChances != 0)
		{
			system("cls");
			goto LoginName;
		}
		else
		{
			cout << LimitHour << " " << LimitMinute << " " << LimitSecond << endl;
			cout << System.GetCurrentHour() << " " << System.GetCurrentMinute() << " " << System.GetCurrentSecond() << endl;
			System.UpdateHours();
			if (System.GetCurrentHour() >= LimitHour)
			{
				if (System.GetCurrentMinute() >= LimitMinute)
				{
					if (System.GetCurrentSecond() >= LimitSecond)
					{
						LimitOfChances = 3;
						system("cls");
						goto LoginName;
					}
				}
				else
				{
					LimitOfChances = 3;
					system("cls");
					goto LoginName;
				}
			}
			else
			{
				LimitOfChances = 3;
				system("cls");
				goto LoginName;
			}
			Error(10);
			goto PreLogin;
		}
		break;
	case 2:
		Error(IncludeUser(Users));
		break;
	case 0:
		return 0;
		break;
	default:
		Error(3);
		goto PreLogin;
		break;
	}
	goto PreLogin;
//Sistema de Login:
LoginName:
	cout << " > Faça Login!\n Usuário: ";
	cin >> Nick;
	for (int X = 0; X < MAX; X++)
	{
		if (Users[X].CompareNick(Nick) == 0)
		{
			UserAccount = X;
			system("cls");
			goto LoginPassword;
		}
	}
	Error(1);
	LimitOfChances--;
	if (LimitOfChances == 0)
	{
		Error(10);
		System.UpdateHours();
		LimitSecond = System.GetCurrentSecond() + 30;
		LimitMinute = System.GetCurrentMinute();
		LimitHour = System.GetCurrentHour();
		if (LimitSecond + 30 > 59)
		{
			LimitSecond -= 59;
			LimitMinute++;
		}
		if (LimitMinute > 59)
		{
			LimitMinute -= 59;
			LimitHour++;
		}
		goto PreLogin;
	}
	goto LoginName;
LoginPassword:
	cout << " > Faça Login!\n Usuário: *****\n Senha: ";
	cin >> Password;
	if (Users[UserAccount].ComparePassword(Password) == 0)
	{
		system("cls");
		goto Menu;
	}
	Error(2);
	LimitOfChances--;
	if (LimitOfChances == 0)
	{
		Error(10);
		System.UpdateHours();
		LimitSecond = System.GetCurrentSecond()+30;
		LimitMinute = System.GetCurrentMinute();
		LimitHour = System.GetCurrentHour();
		if (LimitSecond > 59)
		{
			LimitSecond -= 59;
			LimitMinute++;
		}
		if (LimitMinute > 59)
		{
			LimitMinute -= 59;
			LimitHour++;
		}
		goto PreLogin;
	}
	goto LoginPassword;
//Menu Principal:
Menu:
	for (int W = 0; W < MAX; W++)
	{
		if (Products[W].GetValidity() == 0 && Products[W].GetStatus() == 1)
		if (System.GetCurrentDay() >= Products[W].GetValidityDay())
		{
			if (System.GetCurrentMonth() >= Products[W].GetValidityMonth())
			{
				if (System.GetCurrentYear() >= Products[W].GetValidityYear())
				{
					system("cls");
					Products[W].SetValidity(1);
					Products[W].GetName_(Value);
					strcat(Description, Value);
					strcat(Description, " passou da Validade!");
					for (int I = 0; I < MAX; I++)
					{
						if (AlertReposition[I].GetShowAlert() == 0)
						{
							AlertValidity[I].SetShowAlert(1);
							AlertValidity[I].SetDescription(Description);
							break;
						}
					}
				}
			}
		}
	}
	for (int Z = 0; Z < MAX; Z++)
	{
		if (AlertReposition[Z].GetShowAlert() == 1)
		{
			AlertReposition[Z].ShowAlertMessage();
		}
		if (AlertValidity[Z].GetShowAlert() == 1)
		{
			AlertValidity[Z].ShowAlertMessage();
		}
	}
	cout << endl;
	System.ShowCurrentDay();
	cout << "\nDigite o Número de Sua Opção:\n 1. Ver Seus Produtos\n 2. Incluir Produto\n 3. Excluir Produto\n 4. Carrinho de Compras\n 5. Preferências de Alertas\n\n 0. LOGOUT\n\n > ";
	cin >> Option;
	system("cls");
	switch (Option)
	{
	case 1:
		Error(SeeYourProducts(Products, AlertReposition));
		break;
	case 2:
		Error(IncludeProduct(Products, UserAccount, Users));
		break;
	case 3:
		Error(ExcludeProduct(Products, -1));
		break;
	case 4:
		Error(ShopCar(ShopLists, Products));
		break;
	case 5:
		Error(AlertPreferences(AlertValidity, AlertReposition));
		break;
	case 0:
		system("cls");
		goto PreLogin;
		break;
	default:
		Error(3);
		goto Menu;
		break;
	}
	goto Menu;
	return 0;
}

//Escopo dos Protótipos:
int SeeYourProducts(Product Products[], Alert AlertReposition[])
{
	char Name[20];
	int Opt[MAX] = {-1};
	int Y;
	int X = InitialVerifier(1, Products, 4);
	if (X != 0)
	{
		return X;
	}
	system("cls");
	cout << "Digite o Produto que quer ver Detalhes ou Digite um número negativo para sair:\n";
	for (int Y = 0; Y < MAX; Y++)
	{
		if (Products[Y].GetStatus() == 1)
		{
			Opt[Y] = Y;
			Products[Y].GetName_(Name);
			cout << " " << Y << ". " << Name << endl;
		}
	}
	cout << "\n > ";
	cin >> X;
	if (X < 0)
	{
		return 0;
	}
	for (int Y = 0; Y < MAX; Y++)
	{
		if (X == Opt[Y])
		{
			goto Resultado;
		}
	}
	return 3;
Resultado:
	system("cls");
	char Owner[20];
	Products[X].GetName_(Name);
	Products[X].GetOwner_(Owner);
	cout << Name << ":\n" << " Validade: " << Products[X].GetValidityDay() << "/" << Products[X].GetValidityMonth() << "/" << Products[X].GetValidityYear() << "\n Quantidade: " << Products[X].GetAmount() << "\n Dono: " << Owner << endl;
	if (Products[X].GetValidity() == 0)
	{
		cout << "\nVocê Deseja Atualizar a Quantidade desse Produto no Estoque?\n 1. Sim\n 2. Não\n\n > ";
		cin >> Y;
		if (Y == 1)
		{
			AlterProduct(Products, X, AlertReposition);
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		system("pause");
		return 0;
	}
}

int AlterProduct(Product Products[], int Opt, Alert AlertReposition[])
{
	system("cls");
	char Description[200] = "!O Produto ";
	char Complete1[] = " se Esgotou e foi enviado a sua Lista de Compras!\n";
	char Complete2[] = " se Esgotou e foi Removido dos seus Produtos!\n";
	char Value[20];
	int Amount;
MenuNewAmount:
	cout << "Digite a Nova Quantidade do Produto, em Embalagens ou em Gramas, '0' quando Acabou:\n Quantidade Atual = " << Products[Opt].GetAmount() << "\n Nova Quantidade = ";
	cin >> Amount;
	if (Amount < 0)
	{
		Error(3);
		goto MenuNewAmount;
	}
	if (Amount == 0)
	{
		Products[Opt].GetName_(Value);
		strcat(Description, Value);
		if (Products[Opt].GetPreference() == 1)
		{
			strcat(Description, Complete1);
			Products[Opt].SetValidity(1);
		}
		else
		{
			strcat(Description, Complete2);
			Products[Opt].SetStatus(0);
		}
		for (int X = 0; X < MAX; X++)
		{
			if (AlertReposition[X].GetShowAlert() == 0)
			{
				AlertReposition[X].SetShowAlert(1);
				AlertReposition[X].SetDescription(Description);
				goto Sucess;
			}
		}
	}
Sucess:
	system("cls");
	cout << "\nOperação Realizada com Sucesso!\n\n";
	system("pause");
	return 0;
}

int IncludeProduct(Product Products[], int UserAccount, User Users[])
{
	char Name_[20], Owner[20];
	int DayValidity, MonthValidity, YearValidity, Amount, Preference;
	int X = InitialVerifier(0, Products, 5);
	if (X < 0)
	{
		return 5;
	}
	cout << "Digite o Nome do Produto:\n > ";
	cin >> Name_;
	system("cls");
MenuDay:
	cout << "Digite a Data de Validade, Pressione 'Enter' a cada valor Inserido:\n > ";
	cin >> DayValidity;
	if (DayValidity < 1 || DayValidity > 31)
	{
		Error(12);
		goto MenuDay;
	}
	system("cls");
MenuMonth:
	cout << "Digite a Data de Validade, Pressione 'Enter' a cada valor Inserido:\n > " << DayValidity << "/";
	cin >> MonthValidity;
	if (MonthValidity < 1 || MonthValidity > 12)
	{
		Error(12);
		goto MenuMonth;
	}
	system("cls");
MenuYear:
	cout << "Digite a Data de Validade, Pressione 'Enter' a cada valor Inserido:\n > " << DayValidity << "/" << MonthValidity << "/";
	cin >> YearValidity;
	if (YearValidity < 2016 || YearValidity > 2100)
	{
		Error(12);
		goto MenuYear;
	}
	system("cls");
MenuAmount:
	cout << "Digite a Quantidade de Embalagens do Produto ou o Peso em Gramas:\n > ";
	cin >> Amount;
	if (Amount < 0)
	{
		Error(3);
		goto MenuAmount;
	}
	system("cls");
MenuPreference:
	cout << "Você Deseja que Esse Produto vá para sua Lista de Compras quando se Esgotar?\n 1. Sim\n 2. Não\n> ";
	cin >> Preference;
	if (Preference != 1 && Preference != 2)
	{
		Error(3);
		goto MenuPreference;
	}
	for (X = 0; X < MAX; X++)
	{
		if (Products[X].GetStatus() == 0)
		{
			break;
		}
	}
	Users[UserAccount].GetNick(Owner);
	Products[X].SetName_(Name_);
	Products[X].SetOwner_(Owner);
	Products[X].SetValidityDay(DayValidity);
	Products[X].SetValidityMonth(MonthValidity);
	Products[X].SetValidityYear(YearValidity);
	Products[X].SetAmount(Amount);
	Products[X].SetPreference(Preference);
	Products[X].SetStatus(1);
	for (int W = 0; W < 20; W++)
	{
		toupper(Name_[W]);
	}
	system("cls");
	Suggest(Name_);
	cout << "Operação Concluída com Sucesso!\n" << endl;
	system("pause");
	return 0;
}

int ExcludeProduct(Product Products[], int AutoExclude)
{
	char Name[20];
	int Opt[MAX];
	if (AutoExclude < 0)
	{
		int X = InitialVerifier(1, Products, 4);
		if (X != 0)
		{
			return X;
		}
		system("cls");
		cout << "Digite o Produto que quer Excluir ou Digite um número negativo para sair:\n";
		for (int Y = 0; Y < MAX; Y++)
		{
			if (Products[Y].GetStatus() == 1)
			{
				Opt[Y] = Y;
				Products[Y].GetName_(Name);
				cout << " " << Y << ". " << Name << endl;
			}
		}
		cout << "\n > ";
		cin >> X;
		if (X < 0)
		{
			return 0;
		}
		for (int Y = 0; Y < MAX; Y++)
		{
			if (X == Opt[Y])
			{
				goto Resultado;
			}
		}
		return 3;
	Resultado:
		Products[X].SetStatus(0);
		Products[X].SetValidity(0);
		system("cls");
		cout << "Operação Concluída com Sucesso!\n" << endl;
		system("pause");
		return 0;
	}
	else
	{
		Products[AutoExclude].SetStatus(0);
		Products[AutoExclude].SetValidity(0);
		return 0;
	}
}

int ShopCar(ShopList ShopLists, Product Products[])
{
	int X = InitialVerifier(1, ShopLists, Products, 6);
	if (X != 0)
	{
		return X;
	}
	system("cls");
	char Name[20];
	int Count = 0;
	cout << "Lista de Compras:\n";
	for (int Y = 0; Y < MAX; Y++)
	{
		if (Products[Y].GetStatus() == 1)
		{
			if (Products[Y].GetPreference() == 1)
			{
				if (Products[Y].GetValidity() == 1)
				{
					Products[Y].GetName_(Name);
					cout << " " << Count << ". " << Name << endl;
					Count++;
				}
			}
		}
	}
	system("pause");
	return 0;
}

int AlertPreferences(Alert AlertValidity[], Alert AlertReposition[])
{
Menu:
	int Option = 0, X = 0, Opt[MAX] = {-1};
	cout << "Deseja Verificar Preferências dos:\n 1. Alertas de Validade\n 2. Alertas de Reposição\n\n 0. Voltar a Tela Anterior\n\n > ";
	cin >> Option;
	switch (Option)
	{
	case 1:
		X = InitialVerifier(1, AlertValidity, 7);
		goto Validity;
		break;
	case 2:
		X = InitialVerifier(1, AlertReposition, 8);
		goto Reposition;
		break;
	case 0:
		return 0;
		break;
	default:
		Error(3);
		goto Menu;
		break;
	}
Validity:
	if (X != 0)
	{
		return X;
	}
	system("cls");
	cout << "Digite o Alerta que quer ver Desativar ou um número Negativo para sair:\n";
	for (int Y = 0; Y < MAX; Y++)
	{
		if (AlertValidity[Y].GetShowAlert() == 1)
		{
			Opt[Y] = Y;
			cout << " " << Y << ". ";
			AlertValidity[Y].ShowAlertMessage();
		}
	}
	cout << "\n > ";
	cin >> X;
	if (X < 0)
	{
		return 0;
	}
	for (int Y = 0; Y < MAX; Y++)
	{
		if (X == Opt[Y])
		{
			system("cls");
			AlertValidity[X].SetShowAlert(0);
			cout << "\nSucesso! O Alerta foi Desativado!\n\n";
			system("pause");
			return 0;
		}
	}
	return 3;
Reposition:
	if (X != 0)
	{
		return X;
	}
	system("cls");
	cout << "Digite o Alerta que quer ver Desativar ou um número Negativo para sair:\n";
	for (int Y = 0; Y < MAX; Y++)
	{
		if (AlertReposition[Y].GetShowAlert() == 1)
		{
			Opt[Y] = Y;
			cout << " " << Y << ". ";
			AlertReposition[Y].ShowAlertMessage();
		}
	}
	cout << "\n > ";
	cin >> X;
	if (X < 0)
	{
		return 0;
	}
	for (int Y = 0; Y < MAX; Y++)
	{
		if (X == Opt[Y])
		{
			system("cls");
			AlertReposition[X].SetShowAlert(0);
			cout << "\nSucesso! O Alerta foi Desativado!\n\n";
			system("pause");
			return 0;
		}
	}
	return 3;
}

int InitialVerifier(int Status, Alert Alerts[], int Error)
{
	int Y = 0, Z = 0;
	for (int X = 0; X < MAX; X++)
	{
		Z = Alerts[X].GetShowAlert();
		if (Z == Status)
		{
			return 0;
		}
		else
		{
			Y++;
		}
	}
	if (Y == MAX)
	{
		return Error;
	}
	return 0;
}

int InitialVerifier(int Status, Product Products[], int Error)
{
	int Y = 0, Z = 0;
	for (int X = 0; X < MAX; X++)
	{
		Z = Products[X].GetStatus();
		if (Z == Status)
		{
			return 0;
		}
		else
		{
			Y++;
		}
	}
	if (Y == MAX)
	{
		return Error;
	}
	return 0;
}

int InitialVerifier(int Status, ShopList ShopLists, Product Products[], int Error)
{
	int Y = 0, Z = 0;
	for (int X = 0; X < MAX; X++)
	{
		Z = Products[X].GetPreference();
		if (Z == Status)
		{
			return 0;
		}
		else
		{
			Y++;
		}
	}
	if (Y == MAX)
	{
		return Error;
	}
	return 0;
}

int IncludeUser(User Users[])
{
	char Nick[20];
	char Password[15];
	char PasswordConfirm[15];
	int Avaible;
	for (Avaible = 0; Avaible < MAX; Avaible++)
	{
		if (Users[Avaible].GetStatus() == 0)
		{
			system("cls");
			goto MenuNick;
		}
	}
	return 5;
MenuNick:
	cout << "Digite o NICK de Usuário desejado:\n > ";
	cin >> Nick;
	for (int X = 0; X < MAX; X++)
	{
		if (Users[X].CompareNick(Nick) == 0)
		{
			Error(13);
			goto MenuNick;
		}
	}
	system("cls");
MenuPassword:
	cout << "Digite a SENHA desejada:\n > ";
	cin >> Password;
	system("cls");
	cout << "Digite a SENHA Novamente, para Confirmação:\n > ";
	cin >> PasswordConfirm;
	if (strcmp(Password, PasswordConfirm) != 0)
	{
		Error(14);
		goto MenuPassword;
	}
	Users[Avaible].SetNick(Nick);
	Users[Avaible].SetPassword(Password);
	Users[Avaible].SetStatus(1);
	system("cls");
	cout << "\nOperação Concluída com Sucesso!" << endl;
	system("pause");
	return 0;
}

int Suggest(char Name_[])
{
	if (strcmp(Name_, "FRANGO") == 0)
	{
		cout << "\nSugestão: Frango deve ser Armazenado no Congelador caso não for consumido no período de 1 Semana!\n\n";
	}
	if (strcmp(Name_, "ARROZ") == 0)
	{
		cout << "\nSugestão: Arroz deve ser Lavado com uma Peneira antes de ser Usado e deve ser Amazenado em um local sem Humidade!\n\n";
	}
	if (strcmp(Name_, "QUEIJO") == 0)
	{
		cout << "\nSugestão: Queijos devem ser mantidos na Geladeira, e devem ser consumidos o Quanto antes. Sempre cobertos para não endurecerem!\n\n";
	}
	if (strcmp(Name_, "PRESUNTO") == 0)
	{
		cout << "\nSugestão: Presuntos devem ser mantidos na Geladeira, e devem ser consumidos o Quanto antes. Sempre cobertos para não endurecerem!\n\n";
	}
	if (strcmp(Name_, "PÃO") == 0 || strcmp(Name_, "PAO") == 0)
	{
		cout << "\nSugestão: Pães endurecem rapidamente, então consuma o quanto antes. Mas mesmo duros, ainda podem ser usados em receitas como Rabanada!\n\n";
	}
	if (strcmp(Name_, "SUCO") == 0)
	{
		cout << "\nSugestão: Sucos Naturais devem ser consumidos Imediatamente, para serem aproveitados todos os nutrientes. A Laranja por exemplo perde 50% da Vitamina C, após 30 minutos!\n\n";
	}
	if (strcmp(Name_, "IOGURTE") == 0)
	{
		cout << "\nSugestão: Iogurtes devem ser armazenados na geladeira. É preciso se atentar a validade dos laticínios em Geral, mas podem ser consumidos não muito tempo depois de sua validade sem problemas!\n\n";
	}
	return 0;
}

void Error(int indice)
{
	switch (indice)
	{
	case 0:
		system("cls");
		return;
		break;
	case 1:
		system("cls");
		cout << "Erro " << indice << ": Usuário Inválido! Tente Novamente!\n" << endl;
		break;
	case 2:
		system("cls");
		cout << "Erro " << indice << ": Senha Inválida! Tente Novamente!\n" << endl;
		break;
	case 3:
		system("cls");
		cout << "Erro " << indice << ": Digite Uma Opção Válida!\n" << endl;
		break;
	case 4:
		system("cls");
		cout << "Erro " << indice << ": Não Existem Produtos Cadastrados Ainda!\n" << endl;
		break;
	case 5:
		system("cls");
		cout << "Erro " << indice << ": Foi Atingido O Limite De Cadastros!\n" << endl;
		break;
	case 6:
		system("cls");
		cout << "Erro " << indice << ": Não Existem Produtos Para Sua Lista De Compras!\n" << endl;
		break;
	case 7:
		system("cls");
		cout << "Erro " << indice << ": Não Existem Alertas de Validade Cadastrados!\n" << endl;
		break;
	case 8:
		system("cls");
		cout << "Erro " << indice << ": Não Existem Alertas de Reposição Cadastrados!\n" << endl;
		break;
	case 9:
		system("cls");
		cout << "Erro " << indice << ": Função em Construção ou em Manutenção!\n" << endl;
		break;
	case 10:
		system("cls");
		cout << "Erro " << indice << ": Limite de Tentativas Excedido, aguarde 30 Segundos!\n" << endl;
		break;
	case 11:
		system("cls");
		cout << "Erro " << indice << ": Erro Interno, Valores de Parâmetros Incorretos!\n" << endl;
		break;
	case 12:
		system("cls");
		cout << "Erro " << indice << ": Digite de Um a Dois Dígitos Válidos para Data e Mês, e Quatro Dígitos Válidos para o Ano!\n" << endl;
		break;
	case 13:
		system("cls");
		cout << "Erro " << indice << ": Usuário ja Cadastrado com esse Nick, escolha Outro!\n" << endl;
		break;
	case 14:
		system("cls");
		cout << "Erro " << indice << ": Senhas não Batem, Tente Novamente!\n" << endl;
		break;
	default:
		system("cls");
		cout << "Erro " << indice << ": Erro Desconhecido Pelo Sistema!\n" << endl;
		break;
	}
	return;
}