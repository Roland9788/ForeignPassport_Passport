#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <Windows.h>
using namespace std;


struct Visa
{
	char Country[255];
	int Time_of_action;

};

template<typename T>
int Checking_the_date(T year, T  mounth, T day)
{
	if (year + 14 > 2022)
	{
		cout << "\n�� �� ����� �������� ������� �� 14 ��� �� ��������� ��\n";
		return 2;
	}

	int leapyear;
	int maxday = 0;
	int falg;
	int maxmounth = 12;
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				leapyear = 1;
			}
			else
			{
				leapyear = 0;
			}
		}
		else
		{
			leapyear = 0;
		}
	}
	else
	{
		leapyear = 0;
	}

	do
	{
		if (mounth > maxmounth)
		{
			cout << "\n�����  �� ����� ���� ������ ���-�� �������\n";
			return 2;
		}
		else
		{
			break;
		}
	} while (true);

	if (mounth == 1)
	{
		maxday = 31;
	}
	if (leapyear == 1 && mounth == 2)
	{
		maxday = 29;
	}
	if (leapyear == 0 && mounth == 2)
	{
		maxday = 28;
	}
	if (mounth == 3)
	{
		maxday = 31;
	}
	if (mounth == 4)
	{
		maxday = 30;
	}
	if (mounth == 5)
	{
		maxday = 31;
	}
	if (mounth == 6)
	{
		maxday = 30;
	}
	if (mounth == 7)
	{
		maxday = 31;
	}
	if (mounth == 8)
	{
		maxday = 31;
	}
	if (mounth == 9)
	{
		maxday = 30;
	}
	if (mounth == 10)
	{
		maxday = 31;
	}
	if (mounth == 11)
	{
		maxday = 30;
	}
	if (mounth == 12)
	{
		maxday = 31;
	}

	do
	{
		if (day > maxday)
		{
			cout << "\n���� �� ����� ���� ������ ���-�� ���� � ������\n";
			return 2;
		}
		else
		{
			break;
		}

	} while (true);


	return 1;
}

template<typename T>
int Checking_the_Char(T* obj)
{
	for (int i = 0; i < strlen(obj); i++)
	{
		if (65 > obj[i] && obj[i] > 90 && 97 > obj[i] && obj[i] > 122 && '�' < obj[i] && obj[i] < '�')
		{
			cout << "\n�������� ����\n";
			return 1;
		}
	}
	return 0;
}

class Passport
{
protected:
	int Series;
	int Number;
	int Day;
	int Mounth;
	int Year;
	char Name[255];
	char Surname[255];
	char Patronymic[255];
	int count = 0;
public:

	Passport()
	{
		Series = 0;
		Number = 0;
		Day = 0;
		Mounth = 0;
		Year = 0;
		strcpy(Name, "None");
		strcpy(Surname, "None");
		strcpy(Patronymic, "None");
	}

	Passport(int series, int number, int day, int mounth, int year, const char* name, const char* surname, const char* patronymic)
	{
		Series = series;
		Number = number;
		Day = day;
		Mounth = mounth;
		Year = year;
		strcpy(Name, name);
		strcpy(Surname, surname);
		strcpy(Patronymic, patronymic);
	}

	void Add_info()
	{
		do
		{
			cout << "\n������� ������ ��������\n";
			cout << "\n������� ���\n";
			cin >> Name;
		} while (Checking_the_Char(Name) == 1);
		do
		{
			cout << "\n������� �������\n";
			cin >> Surname;
		} while (Checking_the_Char(Surname) == 1);
		do
		{
			cout << "\n������� ��������\n";
			cin >> Patronymic;
		} while (Checking_the_Char(Patronymic) == 1);



		int flag = 1;
		do
		{
			cout << "\n������� ����� ��������\n";
			cin >> Series;
			if (Series > 9999 || Series < 1000)
			{
				flag = 1;
				cout << "\n�������� ���� (� ����� �������� ������ ���� 4 �����)\n";
				cout << "\n���������� ��� ���\n";
			}
			else
			{
				flag = 0;
			}

		} while (flag != 0);
		do
		{
			cout << "\n������� ����� ��������\n";
			cin >> Number;

			if (Number > 999999 || Number < 100000)
			{
				flag = 1;
				cout << "\n�������� ���� (� ������ �������� ������ ���� 6 ����)\n";
				cout << "\n���������� ��� ���\n";
			}
			else
			{
				flag = 0;
			}
		} while (flag != 0);


		do
		{
			cout << "\n������� ���� ��������\n";
			cout << "\n������� ��� ��������\n";
			cin >> Year;
			cout << "\n������� ����� ��������\n";
			cin >> Mounth;
			cout << "\n������� ���� ��������\n";
			cin >> Day;
			Checking_the_date(Year, Mounth, Day);
		}while (Checking_the_date(Year, Mounth, Day) != 1);

		count++;
	}

	char* GetName()
	{
		return Name;
	}

	char* GetSurname()
	{
		return Surname;
	}

	char* GetPatronymic()
	{
		return Patronymic;
	}

	void SetName()
	{
		cout << "\n������� ���\n";
		cin >> Name;
	}

	void SetSurname()
	{
		cout << "\n������� ���\n";
		cin >> Surname;
	}

	void SetPatronymic()
	{
		cout << "\n������� ���\n";
		cin >> Patronymic;
	}

	void SetDate()
	{
		do
		{
			cout << "\n������� ���� ��������\n";
			cout << "\n������� ��� ��������\n";
			cin >> Year;
			cout << "\n������� ����� ��������\n";
			cin >> Mounth;
			cout << "\n������� ���� ��������\n";
			cin >> Day;
			Checking_the_date(Year, Mounth, Day);
		} while (Checking_the_date(Year, Mounth, Day) != 1);
	}

	void SetSeries()
	{
		int flag = 1;
		do
		{
			cout << "\n������� ����� ��������\n";
			cin >> Series;
			if (Series > 9999 || Series < 1000)
			{
				flag = 1;
				cout << "\n�������� ���� (� ����� �������� ������ ���� 4 �����)\n";
				cout << "\n���������� ��� ���\n";
			}
			else
			{
				flag = 0;
			}
		} while (flag != 0);
	}

	void SetNumber()
	{
		int flag = 1;
		do
		{
			cout << "\n������� ����� ��������\n";
			cin >> Number;
			if (Number > 999999 || Number < 100000)
			{
				flag = 1;
				cout << "\n�������� ���� (� ������ �������� ������ ���� 6 ����)\n";
				cout << "\n���������� ��� ���\n";
			}
			else
			{
				flag = 0;
			}
		} while (flag != 0);

	}

	int GetCount()
	{
		return count;
	}

	void ShowPasport()
	{
		cout << "\n�������\n";
		cout << "****************" << "   �������   " << Surname << "\n";
		cout << "*              *" << "   ���       " << Name << "\n";
		cout << "*              *" << "   ��������  " << Patronymic << "\n";
		cout << "*   ���� ����  *" << "   ���� �������� " << Day << "." << Mounth << "." << Year << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "****************" << "\n";
		cout << " �����: " << Series << "       " << "�����: " << Number;

	}

};

class ForeignPassport :public Passport
{

	Visa* obj;
	int Number_of_visas;
	int Series_ForeginPassport;
	int Number_ForeginPassport;

public:

	ForeignPassport() 
	{
		Number_of_visas = 0;
	}

	ForeignPassport(int number_of_visas)
	{
		Number_of_visas = number_of_visas;
	}

	void Add_Visa()
	{
		cout << "\n���������� ������ � �����\n";
		cout << "\n������� ���������� ���\n";
		cin >> Number_of_visas;
		obj = new Visa[Number_of_visas];
		for (int i = 0; i < Number_of_visas; i++)
		{
			cout << "\n������� " << i + 1 << " ���������� ������\n";
			cin >> obj[i].Country;
			cout << "\n������� ����� �������� " << i + 1 << " ����(� ����)\n";
			cin >> obj[i].Time_of_action;
		}
	}

	void Show_Visa_info()
	{
		cout << "\n���������� ���\n";
		cout << Number_of_visas;
		for (int i = 0; i < Number_of_visas; i++)
		{
			cout <<"\n" << i + 1 << ".���������� ������\n";
			cout << obj[i].Country << "\n";
			cout << "\n���������� ���� �������� � ������ \n";
			cout << obj[i].Time_of_action << "\n";
		}


	}

	void Add_Nuber_Series()
	{
		cout << "\n��������� ������ ������ ������ ��������\n";

		int flag = 1;
		do
		{
			cout << "\n������� �����\n";
			cin >> Series_ForeginPassport;
			if (Series_ForeginPassport > 99 || Series_ForeginPassport < 10)
			{
				flag = 1;
				cout << "\n�������� ���� (� ����� �������������� ������ ���� 2 �����)\n";
				cout << "\n���������� ��� ���\n";
			}
			else
			{
				flag = 0;
			}
		} while (flag != 0);
		do
		{
			cout << "\n������� �����\n";
			cin >> Number_ForeginPassport;
			if (Number_ForeginPassport > 9999999 || Number_ForeginPassport < 1000000)
			{
				flag = 1;
				cout << "\n�������� ���� (� ������ �������������� ������ ���� 7 �����)\n";
				cout << "\n���������� ��� ���\n";
			}
			else
			{
				flag = 0;
			}
		} while (flag != 0);
	}

	void SetSeries_ForeginPassport()
	{
		int flag = 1;
		do
		{
			cout << "\n������� �����\n";
			cin >> Series_ForeginPassport;
			if (Series_ForeginPassport > 99 || Series_ForeginPassport < 10)
			{
				flag = 1;
				cout << "\n�������� ���� (� ����� �������������� ������ ���� 2 �����)\n";
				cout << "\n���������� ��� ���\n";
			}
			else
			{
				flag = 0;
			}
		} while (flag != 0);
	}

	void SetNumber_ForeginPassport()
	{
		int flag = 1;
		do
		{
			cout << "\n������� �����\n";
			cin >> Number_ForeginPassport;
			if (Number_ForeginPassport > 9999999 || Number_ForeginPassport < 1000000)
			{
				flag = 1;
				cout << "\n�������� ���� (� ������ �������������� ������ ���� 7 �����)\n";
				cout << "\n���������� ��� ���\n";
			}
			else
			{
				flag = 0;
			}
		} while (flag != 0);

	}

	void ShowForeignPassport()
	{
		cout << "\n�������������\n";
		cout << "****************" << "   �������   " << Surname << "\n";
		cout << "*              *" << "   ���      " << Name <<"  " << Patronymic << "\n";
		cout << "*              *" << "\n";
		cout << "*   ���� ����  *" << "   ���� �������� " << Day << "." << Mounth << "." << Year << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "****************" << "\n";
		cout << " �����: " << Series_ForeginPassport << "       " << "�����: " << Number_ForeginPassport;

	}

	void SaveToFile()
	{
		char NameFile[80];
		cout << "\n������� ���� � �����\n";
		cin >> NameFile;
		ofstream f(NameFile, ios::out | ios::binary | ios::app);
		if (!f)
		{
			exit(1);
		}

		f << "\n�������\n";
		f << "****************" << "   �������   " << Surname << "\n";
		f << "*              *" << "   ���       " << Name << "\n";
		f << "*              *" << "   ��������  " << Patronymic << "\n";
		f << "*   ���� ����  *" << "   ���� �������� " << Day << "." << Mounth << "." << Year << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "****************" << "\n";
		f << " �����: " << Series << "       " << "�����: " << Number;


		f << "\n�������������\n";
		f << "****************" << "   �������   " << Surname << "\n";
		f << "*              *" << "   ���      " << Name << "  " << Patronymic << "\n";
		f << "*              *" << "\n";
		f << "*   ���� ����  *" << "   ���� �������� " << Day << "." << Mounth << "." << Year << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "****************" << "\n";
		f << " �����: " << Series_ForeginPassport << "       " << "�����: " << Number_ForeginPassport;

		f << "\n���������� ���\n";
		f << Number_of_visas;
		for (int i = 0; i < Number_of_visas; i++)
		{
			f << "\n" << i + 1 << ".���������� ������\n";
			f << obj[i].Country << "\n";
			f << "\n���������� ���� �������� � ������ \n";
			f << obj[i].Time_of_action << "\n";
		}

		f << "\n\n\n\n";

		f.close();
		cout << "\n���������� ������� ����������\n";
	}

};

int menu()
{
	int flag = 0;
	int choice;
	cout << "\n\n              ����\n\n";
	cout << "\n      �������� ��������� ��������\n";
	cout << "\n       ->������ ������ � ����������\n";
	cout << "\n      �����\n";
	do
	{
		choice = _getch();
		if (choice == 13 && flag == 0)
		{
			return 1;
		}
		if (choice == 80)
		{
			system("cls");
			cout << "\n\n              ����\n\n";
			cout << "\n     �������� ��������� ��������\n";
			cout << "\n     ������ ������ � ����������\n";
			cout << "\n       ->�����\n";
			flag++;
		}

		if (choice == 72)
		{
			system("cls");
			cout << "\n\n              ����\n\n";
			cout << "\n      �������� ��������� ��������\n";
			cout << "\n       ->������ ������ � ����������\n";
			cout << "\n      �����\n";
			flag--;
		}

		if (choice == 13 && flag == 1)
		{
			return 0;
		}

	} while (choice != 13);

}

int menu2()
{
	int choice;
	do
	{
		cout << "\n�������� ��� ���������� � ��������?(������� 1)\n";
		cout << "\n�������� ������� ��������(������� 2)\n";
		cout << "\n�������� ������������� ��������(������� 3)\n";
		cout << "\n�������� ���� ��������(������� 4)\n";
		cout << "\n����� � ������� ����(������� 0)\n";
		cin >> choice;

		if (choice == 0)
		{
			return 0;
		}

		if (choice == 1)
		{
			return 1;
		}

		if (choice == 2)
		{
			return 2;
		}

		if (choice == 3)
		{
			return 3;
		}

		if (choice == 4)
		{
			return 4;
		}

	} while (true);
}

int menu3()
{
	int choice;

	do
	{


		cout << "\n�������� ��������� �������\n";
		cout << "\n�������� ����������(������� 1)\n";
		cout << "\n������� ����������(������� 2)\n";
		cout << "\n��������������� ����������(������� 3)\n";
		cout << "\n��������� ���������� � ����(������� 4)\n";
		cout << "\n��������� ������ ���������(������� 0)\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 4;
		case 0:
			return 0;

		default:
			break;
		}



	} while (choice != 0);
}

int menu_Search()
{
	int choice;
	do
	{

		cout << "\n�������� ���� �� ������� ����\n";
		cout << "\n����� ���������(������� 1)\n";
		cout << "\n����� ��������������� (������� 2)\n";
		cout << "\n����� ���� ���������� � ��������(������� 3)\n";
		cout << "\n����� � ������� ����(������� 0)\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;

		default:
			break;
		}

	} while (true);

}

int menu_Edit()
{
	int choice;
	int choice2;
	do
	{


		cout << "\n�������� ���� �� ������� ����\n";
		cout << "\n��������������� ���������� � ��������(������� 1) ����������: \n ��� �������������� ���� ���������� ����� ����� � ������ ��� ��������������� � ������ �������� �������������\n";
		cout << "\n��������������� ���������� � ��������������(������� 2)����������:\n ��������������� �������� ������ �����, ����� � ����\n";
		cout << "\n����� � ������� ����(������� 0)\n";
		cin >> choice;
		if (choice == 0)
		{
			return 0;
		}

		if (choice == 1)
		{
			cout << "\n�������� ��� �� ������ ��������������� � ��������\n";
			cout << "\n���(������� 1)\n";
			cout << "\n�������(������� 2)\n";
			cout << "\n��������(������� 3)\n";
			cout << "\n���� ��������(������� 4)\n";
			cout << "\n�����(������� 5)\n";
			cout << "\n�����(������� 6)\n";
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				return 1;
			case 2:
				return 2;
			case 3:
				return 3;
			case 4:
				return 4;
			case 5:
				return 5;
			case 6:
				return 6;

			default:
				break;
			}
		}

		if (choice == 2)
		{
			cout << "\n�������� ��� �� ������ ��������������� � ��������������\n";
			cout << "\n�����(������� 1)\n";
			cout << "\n�����(������� 2)\n";
			cout << "\n��������������� ����(������� 3)\n";
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				return 7;
			case 2:
				return 8;
			case 3:
				return 9;

			default:
				break;
			}



		}


	} while (true);
}

int main()
{

	SetConsoleCP(1251);//������� ���� � ������
	SetConsoleOutputCP(1251);//�������� �� ����� �������� ����� � �������
	cout << (int)'�';
	cout << (int)'�';
	cout << (int)'�';
	cout << (int)'�';
	setlocale(LC_ALL, "Rus");

	int count = 0;
	int Menu = menu();
	int Menu_Search;
	ForeignPassport Humaninfo;
	do
	{
		if (Menu == 1)
		{

			int Menu3 = menu3();
			if (Menu3 == 1)
			{
				count++;

				Humaninfo.Add_info();

				Humaninfo.Add_Nuber_Series();

				Humaninfo.Add_Visa();
				
			}

			if (Menu3 == 2)
			{
				int Menu2;
				do
				{
					Menu2 = menu2();

					if (Menu2 == 1)
					{
						cout << "\n\n";
						Humaninfo.ShowPasport();
						cout << "\n\n";
						Humaninfo.ShowForeignPassport();
						cout << "\n\n";
						Humaninfo.Show_Visa_info();
						
					}

					if (Menu2 == 2)
					{
						cout << "\n\n";
						Humaninfo.ShowPasport();
						cout << "\n\n";
					}

					if (Menu2 == 3)
					{
						cout << "\n\n";
						Humaninfo.ShowForeignPassport();
						cout << "\n\n";
					}

					if (Menu2 == 4)
					{
						cout << "\n\n";
						Humaninfo.Show_Visa_info();
						cout << "\n\n";
					}

					if (Menu2 == 0)
					{
						break;
					}

				} while (Menu2 != 0);
			}

			if (Menu3 == 3)
			{
				int flag = 1;
				do
				{
					if (count == 0)
					{
						cout << "\n�� ��� �� �������� ���������� ��� �� � �������������\n";
						break;
					}
					int Menu_Edit = menu_Edit();
					if (Menu_Edit == 0)
					{
						break;
					}
					switch (Menu_Edit)
					{
					case 1:
						Humaninfo.SetName();
						break;
					case 2:
						Humaninfo.SetSurname();
						break;
					case 3:
						Humaninfo.SetPatronymic();
						break;
					case 4:
						Humaninfo.SetDate();
						break;
					case 5:
						Humaninfo.SetSeries();
						break;
					case 6:
						Humaninfo.SetNumber();
						break;
					case 7:
						Humaninfo.SetSeries_ForeginPassport();
						break;
					case 8:
						Humaninfo.SetNumber_ForeginPassport();
						break;
					case 9:
						Humaninfo.Add_Visa();
						break;

					default:
						break;
					}

					
					flag == 0;
				} while (flag != 0);
				
			}

			if (Menu3 == 4)
			{
				Humaninfo.SaveToFile();
			}

			if (Menu3 == 0)
			{
				return 0;
			}
		}
		if (Menu == 0)
		{
			return 0;
		}

	} while (true);

	return 0;
}