

#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

/* greatest common divisor */
int gcd(int a, int b){
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

class Fraction { /* a fraction, numer/denom */
   int numer; /* numerator of fraction */
   int denom; /* denominator of fraction */
public:
	friend bool operator==(Fraction f1, Fraction f2);
	friend istream& operator>>(istream& IN, Fraction& f);
	Fraction();
	Fraction(int a, int b); // 
	void readFrac();	
	void reduce();
	void print();

};

Fraction::Fraction()
{
	numer = 0;
	denom = 1;
}
Fraction::Fraction(int a, int b)
{
	numer = a;
	denom = b;
	reduce();
}

void Fraction::readFrac()
{
	cin >> numer >> denom;
	reduce();
}

void Fraction::reduce()
{
	//abs 사용
	int g = gcd(abs(numer),abs(denom));
	numer /= g;
	denom /= g;
	if(denom < 0) {
		numer *= -1;
		denom *= -1;
	}
}

void Fraction::print()
{
	cout << numer << "/" << denom << endl;
}
bool operator==(Fraction f1, Fraction f2) {
	f1.reduce();
	f2.reduce();
	if(f1.numer == f2.numer && f1.denom == f2.denom)
		return true;
	else
		return false;
}
istream& operator>>(istream& IN, Fraction& f) {
	IN >> f.numer >> f.denom;
	f.reduce();
	
	return IN;
}

int main()
{
	Fraction f1;
	Fraction f2;
	
	cin >> f1 >> f2;

	if (f1 == f2)
		cout << "same!!" << endl;
	else
		cout << "no" << endl;
	return 0;
}