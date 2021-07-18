#include <iostream>

using namespace std;

class Animal{
public:
	virtual void print()
	{
		cout << "base Animal" << endl;
	}
};

class Dog : public Animal{
public:
	void print()
	{
		cout << "woof woof" << endl;
	}
};

class Pomeranian : public Dog{
public:
	void print()
	{
		cout << "I'm pome" << endl;
	}
};

int main()
{
	Pomeranian* pointer3 = new Pomeranian();
	pointer3->print();
	cout << "--------------------" << endl;
	
	Animal* pointer6 = new Pomeranian();
	pointer6->print();

	return 0;
}