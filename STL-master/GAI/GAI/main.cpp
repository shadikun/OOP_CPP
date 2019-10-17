#include<iostream>
#include<string>
#include<map>
#include<forward_list>
#include"Crime.h"
#include<conio.h>
#include<windows.h>
using namespace std;
using std::cout;
using std::cin;

void print(const map < string, forward_list<Crime>>& database);
void print(const map < string, forward_list<Crime>>& database, const string& id);
void print(const map < string, forward_list<Crime>>& database, const string& start_id, const string& end_id);

void main()
{
	setlocale(LC_ALL, "");
	map<string, forward_list<Crime>>database =
	{
		pair<string,forward_list<Crime>>("BI 6666 BC",{Crime("АТБ на Ляли","Принес в жертву черного барана, в результате чего облил светор кровью барана,и заляпал зебру")}),
		pair<string,forward_list<Crime>>("BI 6667 BC", {Crime("McDonalds", "Плюнул в пост Гаи")}),
		pair<string,forward_list<Crime>>("BI 6668 BC", {Crime("АТБ на Ляли", "Сбил забор возле клумбы")})

	};
	do
	{
		system("CLS");
		char key;
		cout << "\n1. Вывод всей базы;" << endl;
		cout << "2. Вывод информации по номеру;" << endl;
		cout << "3. Вывод информации по диапазону номеров;" << endl;
		cout << "4. Добавление записи;" << endl;
		cout << "Выберите действие: "; cin >> key;
		switch (key)
		{
		case'1': system("CLS"); print(database); break;
		case'2':
		{
			system("CLS");
			string id;
			cout << "Введите номер автомобиля: "; cin.clear();
			cin.clear();
			cin.ignore();
			getline(cin, id);
			print(database, id);
			break;
		}
		case'3':system("CLS");
		{
			string start_id, end_id;
			cout << "Введите начальный номер:  "; 
			cin.sync();
			cin.get();
			getline(cin, start_id);
			cout << "Введите конечный номер:  "; 
			//cin.clear();
			//cin.ignore();
			getline(cin, end_id);
			/*if (start_id == end_id)
			{
				cout << "\nНомера не могут повторяться!\n";
			}*/
			/*else*/ print(database, start_id, end_id);
		}
		case'4':system("CLS");
		{
			string id, place, crime;
			cout << "Добавление квитанции: ";
			cin.sync();
			cin.get();
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			cout << "Введите номер автомобиля:  "; getline(cin, id);
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			cout << "Место проишествия: \n"; getline(cin, place);
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			cout << "Проишествиe: \n"; getline(cin, crime);
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			database[id].push_front(Crime(place, crime));
			break;
		}
		}
	} while (getch() != 27);//для гетч нужно подключить conio.h !
	//	cout<< database.size() << endl;
}
void print(const map< string, forward_list<Crime >> &database)
{
	for (pair<string, forward_list<Crime>> i : database)
	{
		cout << i.first << "\t\n";
		for (Crime j : i.second)
		{
			cout << "Место проишествия: " << j.get_place() << "\t\n" << ".Нарушение:" << j.get_crime() << endl;
		}
	}
}void print(const map< string, forward_list<Crime >> &database, const string& id)
{
	//cout<<database[id].
	bool present_in_base = false;
	for (pair<string, forward_list<Crime>> i : database)
	{
		if (id == i.first)
		{
			present_in_base = true;
			for (Crime j : i.second)
			{
				cout << j.get_place() << "\t\n" << j.get_crime() << endl;
			}
			break;
		}
	}
	if (!present_in_base)cout << "В базе нет такого номера" << endl;
}
void print(const map < string, forward_list<Crime>>& database,  const string& start_id, const string& end_id)
{
	//cout<<database[id].
	bool present_in_base = false;
	for (pair<string, forward_list<Crime>> i : database)
	{
		if (i.first >= start_id && i.first <= end_id)
		{
			present_in_base = true;
			for (Crime j : i.second)
			{
				cout << j.get_place() << "\t\n" << j.get_crime() << endl;
			}
		}
	}
	if (!present_in_base)cout << "В базе нет такого номера" << endl;
}
