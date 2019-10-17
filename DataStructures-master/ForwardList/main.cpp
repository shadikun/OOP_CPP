#include<iostream>
using namespace std;

class Element
{
	int Data;
	Element* pNext;

public:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;

public:
	ForwardList()
	{
		this->Head = nullptr;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
	}
	void push_back(int Data)
	{
		Element* Temp = Head;// Temp - итератор
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;//переход на слде елем
		}
		Element* New = new Element(Data);
		Temp->pNext = New;
	}
	void print()
	{
		Element* Temp = Head;// Temp - итератор
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;//переход на слде елем


		}

	}
};
void main()
{
	setlocale(LC_ALL, "");
	int n; //Колличество элементов
	cout << "Введите колличвество елемментов:  ";
	cin >> n;
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_front(rand() % 100);
	}
	fl.print();
	cout << "\n--------------------\n";
	fl.push_back(123);
	fl.print();
}