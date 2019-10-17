#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<deque>
#include<forward_list>
//Accotiative containers
#include<map>

using namespace std;
using std::cout;

//#define STL_ARRAY
#define STL_VECTOR
//#define STL_DEQUE
//#define STL_FORWARD_LIST
//#define STL_MAP
void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	int Arr[] = { 3,5,8,13,21 };
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	for (int i : Arr)
	{
		cout << i << "\t";
	}
	cout << endl;


	/*int* d_arr = new int[5]{34,88,123};*/
	/*delete[] d_arr;*/

	for (int i : arr)cout << i << "\t"; cout << endl;
#endif // STL_ARRAY
#ifdef STL_VECTOR
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	try
	{
		for (int i = 0; i < vec.size() * 2; i++)
		{
			cout << vec.at(i) << "\t";
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;

	vec.push_back(55);
	vec.push_back(89);

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	cout << "unnornal Revers:" << endl;
	for (vector<int>::iterator it = vec.end() - 1;/* it != vec.begin()*/; it--)
	{
		cout << *it << "\t";
		if (it == vec.begin())break;
	}
	cout << endl;
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	vec.resize(8);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	vec.shrink_to_fit();
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	//cout << vec.empty() << endl;
	vec.reserve(23);
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << vec.back() << endl;

	int index;
	int data;
	cout << "Введите индекс добавляемого элемента:  "; cin >> index;
	cout << "Введите значение добавляемого элемента:  "; cin >> data;
	vector<int>::iterator position = vec.begin() + index;
	vec.insert(position, data);
	for (int i : vec)cout << i << "\t"; cout << endl;
	vec.erase(vec.begin() + index);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	int first_index, second_index;
	cout << "Enter first index number:\t"; cin >> first_index;
	cout << "Enter second index number:\t"; cin >> second_index;
	/*vec.erase(vec.begin() + first_index, vec.begin() +	second_index+1);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;*/
	vec.assign(vec.begin() + first_index, vec.begin() + second_index + 1);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;



#endif // STL_VECTOR
#ifdef STL_DEQUE

	deque<int> dq = { 3,5,8,13,21 };
	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i] << "\t";
	}
	cout << endl;
	/*dq.push_back(34);
	dq.push_back(55);
	dq.push_front(0);
	dq.push_front(1);*/




	dq.insert(dq.begin(), { 0, 1, 1 }); 	dq.insert(dq.end(), { 3, 2, 1 });
	for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
	{
		cout << *it << "\t";
}

#endif // DEQUE
#ifdef STL_FORWARD_LIST
	//forward_list<int> fl = { 3,5,8,13,21 };
//cout << fl.max_size() << endl;


	forward_list<int> fl(5, 1024);
	for (int i : fl)cout << i << "\t"; cout << endl;
	cout << fl.max_size() << endl;

#endif // STL_FORWARD_LIST
#ifdef STL_MAP
	map<int, string> week =
	{
		pair<int,string>(0,"Sunday"),
		pair<int,string>(1,"Monday"),
		pair<int,string>(2,"Tuesday"),
		pair<int,string>(3,"Wednesday"),
		pair<int,string>(4,"Thursday"),
		pair<int,string>(5,"Friday"),
		pair<int,string>(6,"Saturday")
	};
	for (map<int, string>::iterator it = week.begin(); it != week.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "\n===================================================================\n";
	for (pair<int, string>i : week)
	{
		cout << i.first << "\t" << i.second << endl;
	}



#endif // STL_MAP
}