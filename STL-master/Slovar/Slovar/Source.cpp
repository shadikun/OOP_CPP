#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;
using std::cout;
using std::cin;
#define d "\n----------------------------------\n"
#define dd "\n==================================\n"

void main()
{
	setlocale(LC_ALL, "");
	map<string, vector<string>>  dictionary =
	{
		pair<string,vector<string>>("pain",vector<string>{"боль","огорчение"}),
		pair<string,vector<string>>("love",vector<string>{"влюбленность","любовь"}),
		pair<string,vector<string>>("space",vector<string>{"космос","пространство"}),
		pair<string,vector<string>>("void",vector<string>{"пустота","вакууум"}),
		pair<string,vector<string>>("solitude",vector<string>{"одиночество","уединение"}),
		pair<string,vector<string>>("winter",vector<string>{"холод","зима"}),
	};
	//Standart output:
		cout << d;
	for (map<string, vector<string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << it->first << endl<<endl;
		for (vector<string>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			cout << *it2 << endl;
		}
		cout << d;
	}
	cout << dd<<d;
	for (pair<string, vector<string>>i : dictionary)
	{
		cout << i.first <<  endl<<endl;
		for (string j : i.second)
		{
			cout << j << endl;
		}
		cout << d;
	}
	
	vector<int> numbers = { 3,5,8,13,21 };
	for (int i : numbers)
	{
		cout << i << "\t";
	}
	cout << endl;
}