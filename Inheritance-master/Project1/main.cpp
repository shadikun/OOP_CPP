#include<iostream>
#include<string>
using namespace std;

class Human
{
	string first_name;
	string last_name;
	unsigned int age;

public:
	const string& get_first_name() const
	{
		return this->first_name;
	}
	const string& get_last_name() const
	{
		return this->last_name;
	}
	unsigned int get_age() const
	{
		return this->age;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	Human(const string& first_name, const string&  last_name, unsigned int age)
	{
		set_first_name(first_name);
		set_last_name(last_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}

	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	void info()
	{
		cout << last_name << " " << first_name << " " << age << "let.\n";
	}

};
class Student : public Human
{
	string speciality;
	string group;
	unsigned int year;
	unsigned int rating;
public:
	const string& get_speciality()const
	{
		return this->speciality;
	}
	const string& get_group()const
	{
		return this->group;
	}
	unsigned int get_year()const
	{
		return this->year;
	}

	unsigned int get_rating()const
	{
		return this->rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_year(unsigned int year)
	{
		this->year = year;
	}
	void set_group(unsigned int group)
	{
		this->group = group;
	}
	void set_rating(unsigned int rating)
	{
		this->rating = rating;
	}

	Student(const string& first_name, const string& last_name, unsigned int age, const string& speciality, const string&  group, unsigned int year, unsigned int rating) :Human(first_name, last_name, age)
	{
		this->speciality = speciality;
		this->year = year;
		this->rating = rating;
		this->group = group;
		cout << "SConstructor:\t" << this << endl;
	}

	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	void info()
	{
		Human::info();
		cout << speciality << " " << group << " " << year << " kurs,rating " << rating << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	Human h("Василий", "Дурко", 21);
	h.info();
	Student s("Андрей", "Анатольевич", 41, "преподаватель по железу", "СТ ПУ 34а", 1, 0);
	s.info();
}