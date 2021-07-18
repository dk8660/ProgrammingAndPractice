#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

/* greatest common divisor */
int gcd(int a, int b) {
   while (b != 0) {
      int temp = b;
      b = a%b;
      a = temp;
   }
   return a;
}

class Fraction { /* a fraction, numer/denom */
	int numer; /* numerator of fraction */
	int denom; /* denominator of fraction */
public:
	friend istream& operator>>(istream& IN, Fraction& f);
	Fraction();
	Fraction(int a, int b); // 
	void readFrac();
	void reduce();
	void print();
	
};
istream& operator>>(istream& IN, Fraction& f) {
	IN >> f.numer >> f.denom;
	f.reduce();
	
	return IN;
}

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

int main()
{
	
	Fraction f1;
	cin >> f1;
	
	f1.print();
	
	return 0;
	
}