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
		cout << "\nВы не могли получить паспорт до 14 лет на територии РФ\n";
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
			cout << "\nМесяц  не может быть больше кол-ва месяцов\n";
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
			cout << "\nДата не может быть больше кол-ва дней в месяце\n";
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
		if (65 > obj[i] && obj[i] > 90 && 97 > obj[i] && obj[i] > 122 && 'А' < obj[i] && obj[i] < 'я')
		{
			cout << "\nНеверный ввод\n";
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
			cout << "\nВведите данные паспорта\n";
			cout << "\nВведтие имя\n";
			cin >> Name;
		} while (Checking_the_Char(Name) == 1);
		do
		{
			cout << "\nВведите фамилию\n";
			cin >> Surname;
		} while (Checking_the_Char(Surname) == 1);
		do
		{
			cout << "\nВведите отчество\n";
			cin >> Patronymic;
		} while (Checking_the_Char(Patronymic) == 1);



		int flag = 1;
		do
		{
			cout << "\nВведите серию паспорта\n";
			cin >> Series;
			if (Series > 9999 || Series < 1000)
			{
				flag = 1;
				cout << "\nНеверный ввод (В серии паспорта должно быть 4 цыфры)\n";
				cout << "\nПопробуйте ещё раз\n";
			}
			else
			{
				flag = 0;
			}

		} while (flag != 0);
		do
		{
			cout << "\nВведите номер паспорта\n";
			cin >> Number;

			if (Number > 999999 || Number < 100000)
			{
				flag = 1;
				cout << "\nНеверный ввод (В номере паспорта должно быть 6 цыфр)\n";
				cout << "\nПопробуйте ещё раз\n";
			}
			else
			{
				flag = 0;
			}
		} while (flag != 0);


		do
		{
			cout << "\nВведите дату рождения\n";
			cout << "\nВведите год рождения\n";
			cin >> Year;
			cout << "\nВведите месяц рождения\n";
			cin >> Mounth;
			cout << "\nВведите день рождения\n";
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
		cout << "\nВведите имя\n";
		cin >> Name;
	}

	void SetSurname()
	{
		cout << "\nВведите имя\n";
		cin >> Surname;
	}

	void SetPatronymic()
	{
		cout << "\nВведите имя\n";
		cin >> Patronymic;
	}

	void SetDate()
	{
		do
		{
			cout << "\nВведите дату рождения\n";
			cout << "\nВведите год рождения\n";
			cin >> Year;
			cout << "\nВведите месяц рождения\n";
			cin >> Mounth;
			cout << "\nВведите день рождения\n";
			cin >> Day;
			Checking_the_date(Year, Mounth, Day);
		} while (Checking_the_date(Year, Mounth, Day) != 1);
	}

	void SetSeries()
	{
		int flag = 1;
		do
		{
			cout << "\nВведите серию паспорта\n";
			cin >> Series;
			if (Series > 9999 || Series < 1000)
			{
				flag = 1;
				cout << "\nНеверный ввод (В серии паспорта должно быть 4 цыфры)\n";
				cout << "\nПопробуйте ещё раз\n";
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
			cout << "\nВведите номер паспорта\n";
			cin >> Number;
			if (Number > 999999 || Number < 100000)
			{
				flag = 1;
				cout << "\nНеверный ввод (В номере паспорта должно быть 6 цыфр)\n";
				cout << "\nПопробуйте ещё раз\n";
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
		cout << "\nПаспорт\n";
		cout << "****************" << "   Фамилия   " << Surname << "\n";
		cout << "*              *" << "   Имя       " << Name << "\n";
		cout << "*              *" << "   Отчество  " << Patronymic << "\n";
		cout << "*   Ваше фото  *" << "   Дата рождения " << Day << "." << Mounth << "." << Year << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "****************" << "\n";
		cout << " Серия: " << Series << "       " << "Номер: " << Number;

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
		cout << "\nДобавление данных о визах\n";
		cout << "\nВведите количество виз\n";
		cin >> Number_of_visas;
		obj = new Visa[Number_of_visas];
		for (int i = 0; i < Number_of_visas; i++)
		{
			cout << "\nВведите " << i + 1 << " посещаемую страну\n";
			cin >> obj[i].Country;
			cout << "\nВведите время действия " << i + 1 << " визы(В днях)\n";
			cin >> obj[i].Time_of_action;
		}
	}

	void Show_Visa_info()
	{
		cout << "\nКоличетсво виз\n";
		cout << Number_of_visas;
		for (int i = 0; i < Number_of_visas; i++)
		{
			cout <<"\n" << i + 1 << ".Посещаемая страна\n";
			cout << obj[i].Country << "\n";
			cout << "\nКоличество дней прибытия в стране \n";
			cout << obj[i].Time_of_action << "\n";
		}


	}

	void Add_Nuber_Series()
	{
		cout << "\nЗаполните данные вашего загран паспорта\n";

		int flag = 1;
		do
		{
			cout << "\nВведите серию\n";
			cin >> Series_ForeginPassport;
			if (Series_ForeginPassport > 99 || Series_ForeginPassport < 10)
			{
				flag = 1;
				cout << "\nНеверный ввод (В серии загранпаспорта должно быть 2 цыфры)\n";
				cout << "\nПопробуйте ещё раз\n";
			}
			else
			{
				flag = 0;
			}
		} while (flag != 0);
		do
		{
			cout << "\nВведите номер\n";
			cin >> Number_ForeginPassport;
			if (Number_ForeginPassport > 9999999 || Number_ForeginPassport < 1000000)
			{
				flag = 1;
				cout << "\nНеверный ввод (В номере загранпаспорта должно быть 7 цыфер)\n";
				cout << "\nПопробуйте ещё раз\n";
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
			cout << "\nВведите серию\n";
			cin >> Series_ForeginPassport;
			if (Series_ForeginPassport > 99 || Series_ForeginPassport < 10)
			{
				flag = 1;
				cout << "\nНеверный ввод (В серии загранпаспорта должно быть 2 цыфры)\n";
				cout << "\nПопробуйте ещё раз\n";
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
			cout << "\nВведите номер\n";
			cin >> Number_ForeginPassport;
			if (Number_ForeginPassport > 9999999 || Number_ForeginPassport < 1000000)
			{
				flag = 1;
				cout << "\nНеверный ввод (В номере загранпаспорта должно быть 7 цыфер)\n";
				cout << "\nПопробуйте ещё раз\n";
			}
			else
			{
				flag = 0;
			}
		} while (flag != 0);

	}

	void ShowForeignPassport()
	{
		cout << "\nЗагранпаспорт\n";
		cout << "****************" << "   Фамилия   " << Surname << "\n";
		cout << "*              *" << "   Имя      " << Name <<"  " << Patronymic << "\n";
		cout << "*              *" << "\n";
		cout << "*   Ваше фото  *" << "   Дата рождения " << Day << "." << Mounth << "." << Year << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "*              *" << "\n";
		cout << "****************" << "\n";
		cout << " Серия: " << Series_ForeginPassport << "       " << "Номер: " << Number_ForeginPassport;

	}

	void SaveToFile()
	{
		char NameFile[80];
		cout << "\nВведите путь к файлу\n";
		cin >> NameFile;
		ofstream f(NameFile, ios::out | ios::binary | ios::app);
		if (!f)
		{
			exit(1);
		}

		f << "\nПаспорт\n";
		f << "****************" << "   Фамилия   " << Surname << "\n";
		f << "*              *" << "   Имя       " << Name << "\n";
		f << "*              *" << "   Отчество  " << Patronymic << "\n";
		f << "*   Ваше фото  *" << "   Дата рождения " << Day << "." << Mounth << "." << Year << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "****************" << "\n";
		f << " Серия: " << Series << "       " << "Номер: " << Number;


		f << "\nЗагранпаспорт\n";
		f << "****************" << "   Фамилия   " << Surname << "\n";
		f << "*              *" << "   Имя      " << Name << "  " << Patronymic << "\n";
		f << "*              *" << "\n";
		f << "*   Ваше фото  *" << "   Дата рождения " << Day << "." << Mounth << "." << Year << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "*              *" << "\n";
		f << "****************" << "\n";
		f << " Серия: " << Series_ForeginPassport << "       " << "Номер: " << Number_ForeginPassport;

		f << "\nКоличетсво виз\n";
		f << Number_of_visas;
		for (int i = 0; i < Number_of_visas; i++)
		{
			f << "\n" << i + 1 << ".Посещаемая страна\n";
			f << obj[i].Country << "\n";
			f << "\nКоличество дней прибытия в стране \n";
			f << obj[i].Time_of_action << "\n";
		}

		f << "\n\n\n\n";

		f.close();
		cout << "\nИнформация успешно сохраненна\n";
	}

};

int menu()
{
	int flag = 0;
	int choice;
	cout << "\n\n              Меню\n\n";
	cout << "\n      Выбирите дальнешее действие\n";
	cout << "\n       ->Начать работу с программой\n";
	cout << "\n      Выход\n";
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
			cout << "\n\n              Меню\n\n";
			cout << "\n     Выбирите дальнешее действие\n";
			cout << "\n     Начать работу с программой\n";
			cout << "\n       ->Выход\n";
			flag++;
		}

		if (choice == 72)
		{
			system("cls");
			cout << "\n\n              Меню\n\n";
			cout << "\n      Выбирите дальнешее действие\n";
			cout << "\n       ->Начать работу с программой\n";
			cout << "\n      Выход\n";
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
		cout << "\nПоказать всю информацию о человеке?(Введите 1)\n";
		cout << "\nПоказать паспорт человека(Введите 2)\n";
		cout << "\nПоказать загранпаспорт человека(Введите 3)\n";
		cout << "\nПоказать визы человека(Введите 4)\n";
		cout << "\nВыйти в главное меню(Введите 0)\n";
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


		cout << "\nВыберите дальнешее дествие\n";
		cout << "\nДобавить информацию(Введите 1)\n";
		cout << "\nВывести информацию(Введите 2)\n";
		cout << "\nОтредактировать информацию(Введите 3)\n";
		cout << "\nСохранить информацию в файл(Введите 4)\n";
		cout << "\nЗавершить работу программы(Введите 0)\n";
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

		cout << "\nВыбирите один из пунктов меню\n";
		cout << "\nПоиск паспортов(Введите 1)\n";
		cout << "\nПоиск загранпаспортов (Введите 2)\n";
		cout << "\nПоиск всей информации о человеке(Введите 3)\n";
		cout << "\nВыход в главное меню(Введите 0)\n";
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


		cout << "\nВыберите один из пунктов меню\n";
		cout << "\nОтредактировать информацию в паспорте(Введите 1) Примечание: \n При редактировании всей информации кроме серии и номера она отредактируется в загран паспорте автоматически\n";
		cout << "\nОтредактировать информацию в загранпаспорте(Введите 2)Примичание:\n Отредактировать возможно только номер, серию и визы\n";
		cout << "\nВыйти в главное меню(Введите 0)\n";
		cin >> choice;
		if (choice == 0)
		{
			return 0;
		}

		if (choice == 1)
		{
			cout << "\nУточните что вы хотите отредактировать в паспорте\n";
			cout << "\nИмя(Введите 1)\n";
			cout << "\nФамилия(Введите 2)\n";
			cout << "\nОтчество(Введите 3)\n";
			cout << "\nДата рождения(Введите 4)\n";
			cout << "\nСерия(Введите 5)\n";
			cout << "\nНомер(Введите 6)\n";
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
			cout << "\nУточните что вы хотите отредактировать в загранпаспорте\n";
			cout << "\nСерию(Введите 1)\n";
			cout << "\nНомер(Введите 2)\n";
			cout << "\nОтредактировать визы(Введите 3)\n";
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

	SetConsoleCP(1251);//Русский язык в косоли
	SetConsoleOutputCP(1251);//Отвечает за вывод русского языка в консоли
	cout << (int)'А';
	cout << (int)'Я';
	cout << (int)'а';
	cout << (int)'я';
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
						cout << "\nВы ещё не добавили информацию что бы её редактировать\n";
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