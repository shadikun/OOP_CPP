#include<iostream>
using namespace std;
using std::cout;
using std::cin;

//#define EXCEPTION_SYNTAX
//#define DIVISION_BY_ZERO_EXCEPTION
#define FACTORIAL
//#define LONG_LONG_INT_FACTORIAL
long long int factorial(int n);

void main()
{
	setlocale(LC_ALL, "");
#ifdef EXCEPTION_SYNTAX
	try
	{
		throw 123;
		throw "Smth";
	}
	catch (int error)
	{
		cout << "ERROR 404 NOT FOUND" << error << endl;
	}
	catch (const char*error)
	{
		cerr << "ERROR 404 NOT FOUND" << error << endl;
	}
	catch (...)
	{
		cerr << "ERROR 404 NOT FOUND" << endl;
	}

	cout << "Hello that`s ok!\n";
#endif // EXCEPTION_SYNTAX
#ifdef DIVISION_BY_ZERO_EXCEPTION

	int a = 20;
	int b = 0;
	try
	{
		cout << a / b << endl;
	}
	catch (std::exception&e)
	{
		cerr << e.what() << endl;
	}
	catch (...)
	{
		cerr << "ERROR 404 NOT FOUND\n";
	}
	_asm
	{

	}
#endif // DIVISION_BY_ZERO_EXCEPTION
#ifdef FACTORIAL
	int n;
	cout << "Input number to find factorial: "; cin >> n;
	try
	{
		cout << n << " != " << factorial(n) << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
#endif // FACTORIAL
}
//fgh;lkf;ghflh
long long int factorial(int n)
{
	if (n > 20)throw overflow_error("Too large number");//exception("Error: too large number");
	long long int f = 1;

	for (int i = 1; i <= n; i++)
	{
		f *= i;
		/*cout << i << " != ";
		cout << f << endl;*/
	}
return f;
}