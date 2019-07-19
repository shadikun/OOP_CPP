#include<iostream>

using namespace std;

using std::cin;

using std::cout;

using std::endl;

class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//			Constructors:
	//Point()
	//{
	//	x = y = double();	//значение по умолчанию для double.
	//	cout << "DefaultConstruct" << this << endl;
	//}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}

	Point operator++(int)
	{
		Point temp = *this;
		this->x++;
		this->y++;
		return temp;
	}

	//			Methods:
	double distance(const Point& other)
	{
		double x_distance = this->x - other.x; // вычесляем растояние до точки по оси Х
		double y_distance = this->y - other.y; // вычесляем растояние до точки по оси Y
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		//sqrt - Square Root.
		return distance;
	}

	void print(bool from_derived = false) const
	{
		cout << x << "\t" << y;
		if (from_derived)cout << "\t";
		else cout << "\n";	//Если метод вызывается НЕ из дочернего класса - переходим на новую строку.
	}


	friend Point operator+(const Point& A, const Point& B);
};

Point operator+(const Point& left, const Point& right)
{
	//Point temp(left.get_x() + right.get_x(), left.get_y() + right.get_y());
	//temp.x = left.x + right.x;
	//temp.y = left.y + right.y;
	//temp.set_x(left.get_x() + right.get_x());
	//temp.set_y(left.get_y() + right.get_y());
	//return temp;

	return Point(left.get_x() + right.get_x(), left.get_y() + right.get_y());


}

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

class Point3D :public Point
{
	double z;
public:
	double get_z() const
	{
		return z;
	}
	void set_z(double z)
	{
		this->z = z;
	}
	void print()
	{
		Point::print(true);
		cout << z << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	return os << obj.get_x() << "\t" << obj.get_y();
}
std::istream& operator>>(std::istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}

void main()
{

#ifdef ENCAPSULATION
	int a = 2;
	Point A;
	A.set_x(2);
	A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point* pA = &A;
	//cout << pA->get_x() << "\t" << pA->get_y() << endl;
	//cout << (*pA).get_x() << "\t" << (*pA).get_y() << endl;
	pA->print();

	Point3D B;
	B.set_x(4);
	B.set_y(5);
	B.set_z(6);
	cout << B.get_x() << "\t"
		<< B.get_y() << "\t"
		<< B.get_z() << endl;
	B.print();
#endif // ENCAPSULATION

#ifdef CONSTRUCTORS
	int a;	//Объявляется переменная без начального значения.
	Point A;//Создается объект без начального значения. 
			//Здесь вызывается конструктор по умолчанию, 
			//и инициализирует объект значением по умолчанию.
	A.print();
	Point B(2, 3);
	B.print();
	Point C = 5;
	C.print();
	Point D(5);
	D.print();
	cout << "\n-----------------------------------\n";
	//Point E = D;	//CopyConstructor
	B.print();
	cout << A.distance(B) << endl;
	cout << distance(A, B) << endl;
	B.print();
	cout << "\n-----------------------------------\n";
	A = B;
#endif

#ifdef ARITHMETIC_OPERATORS_CHECKS
	int a = 2;
	int b = 3;
	cout << a + b << endl;


	Point A(2, 3);
	A.print();
	Point B(4, 5);
	B.print();
	Point C = A + B;
	C.print();
	A += B;
	A.print();
	++A;
	A.print();
#endif

	Point A(2, 3);
	Point B = A++;
	A.print();
	B.print();
	cout << A << endl;
	cout << "Input cordinates: ";
	cin >> A;
	cout << A << endl;
}