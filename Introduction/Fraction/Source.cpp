#include<iostream>

using namespace std;
//TODO:
//Реализовать класс Function, описующий простую дробь;
//Дробь состоит из целой части (integer), числителя (numerator), и знаменателя (denominator).
// В классе должны бить методы (конструктор и деструктор)
// а также доп методы:
// to-proper()- делать дробь правильной;
// to improper()- делает дробь не правильной;
// Перегрузить арифметический операторы (+, -, *, /)

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:

	int get_integer() const
	{
		return integer;
	}

	int get_numerator() const
	{
		return numerator;
	}

	int get_denominator() const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}

	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}

	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}


	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor: \t" << this << endl;
	}
	 explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor: \t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor: \t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor: \t" << this << endl;
	}
	~Fraction()
	{	
		cout << "Destructor: \t" << this << endl;
	}

	explicit operator int()
	{
		return this->integer;
	}
	
	operator double()
	{
		double temp = integer;
		temp += (double)numerator / denominator;
		return temp;
	}

	void to_proper()
	{
		integer = numerator / denominator;
		numerator %= denominator;
	}

	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}
};

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if(obj.get_integer())os <<"("<< obj.get_numerator() << "/" << obj.get_denominator()<<")";
		else os << obj.get_numerator() << "/" << obj.get_denominator();
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	return os;
}



void main()
{
	/*Fraction A(15, 4);
	cout << A << endl;
	A.to_proper();
	cout << A << endl;
	A.to_improper();
	cout << A << endl;
	Fraction B;
	cout << B << endl;
	*/

	int a = 2; // no constructor
	int b = 3.5; // double to int
	double c = 5; // from int to double
    Fraction A = (Fraction)5; // from int to Fraction
	                // single argumment
	Fraction B(1, 2);
	B = (Fraction)5; // from int to Fraction
	        //CopyAssignment

	int d = (int)B;
	cout << B << endl;
	cout << d << endl;
}