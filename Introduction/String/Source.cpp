#include<iostream>

using namespace std;
using std::cout;

#define delimeter "\n---------------------------------------\n"
//#define CONSTRUCTOR_CHECK

class String;
String operator+(const String& left, const String& right);

class String
{
	int size; // размер строки
	char* str; // адресс строки в динам памяти.
public:
	int get_size() const
	{
		return size;
	}
	const char* get_str() const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	      }

	//Constructors:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {} ;
		cout << "DefConstructor:\t" << this << endl;
	}

	String(const char* str)
	{
		this->size = strlen(str)+1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor: " << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor: " << this << endl;
	}

	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor: "<< this << endl;
	}

	String& operator=(String&& other) 
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAsignment: " << this << endl;
		return *this;
	}

	~String()
	{
		delete[] this->str;
		cout << "Destructor\t" << this << endl;
	}
	// Operators 

	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor: " << this << endl;
		return *this;
	}

	String& operator+=(const  String& other)
	{
		return *this = *this + other;
	}


	void print()
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}

};
 
String operator+(const String& left, const String& right)
{
	String buffer = left.get_size() + right.get_size()-1;
	for (int i = 0; left.get_str()[i]; i++)
	{
		buffer.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; right.get_str()[i]; i++)
	{
		buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return buffer;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK


	String str0;
	cout << str0 << endl;
	//	str0.print();
	cout << typeid("Hello").name() << endl;
	String str1 = "Hello";
	str1.print();
	String str2 = str1;
	str2.print();
	str0 = str1;
	str0.print();
	cout << "\n----------------------------\n" << endl;
	str2 = str2;
	str2.print();
	cout << "\n----------------------------\n" << endl;
#endif 

	String str1 = "hello";
	String str2 = "world";
	cout << delimeter << endl;
	String str3 = str1 +" "+ str2;
	str3.print();
	cout << delimeter << endl;
	str3 = str1 + " " + str2;
	cout << str3 << endl;
	cout << delimeter << endl;
}