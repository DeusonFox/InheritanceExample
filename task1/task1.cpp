// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

class B
{
	int a;
public:
	B() { cout << "Object of " << typeid(*this).name() << " was created\n"; }
	B(int x) : B() { a = x; }
	~B() { cout << "Object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D1 : virtual public B
{
	int b;
public:
	D1(int x, int y) : B(y)
	{
		b = x;
		cout << "Object of " << typeid(*this).name() << " was created\n";
	}
	~D1() { cout << "Object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D2 : virtual private B
{
	int c;
public:
	D2(int x, int y) : B(y)
	{
		c = x;
		cout << "Object of " << typeid(*this).name() << " was created\n";
	}
	~D2() { cout << "Object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D3 : virtual private B
{
	int d;
public:
	D3(int x, int y, int z, int i, int j) : B(y)
	{
		d = x;
		cout << "Object of " << typeid(*this).name() << " was created\n";
	}
	~D3() { cout << "Object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D4 : private D1
{
	int e;
public:
	D4(int x, int y, int z, int i, int j) : D1(i, j)
	{
		e = x;
		cout << "Object of " << typeid(*this).name() << " was created\n";
	}
	~D4() { cout << "Object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D5 : public D1, public D2, private D3
{
	int f;
public:
	D5(int x, int y, int z, int i, int j) : D1(i, j), D2(z, y), D3(j, x, y, i, j)
	{
		f = x;
		cout << "Object of " << typeid(*this).name() << " was created\n";
	}
	~D5() { cout << "Object of " << typeid(*this).name() << " was destroyed\n"; }
};

int main()
{
	D4 temp(100, 200, 300, 400, 500);
	D5 temp1(1, 2, 3, 4, 5);
}