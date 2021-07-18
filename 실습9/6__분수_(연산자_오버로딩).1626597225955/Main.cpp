

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
	friend Fraction operator+(Fraction &f1, Fraction &f2);
	friend Fraction operator-(Fraction &f1, Fraction &f2);
	friend istream& operator>>(istream& IN, Fraction& f);
	Fraction();
	Fraction(int a, int b); // 
	void readFrac();	
	void reduce();
	void print();
	Fraction add(Fraction f);
	Fraction& operator--();
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

Fraction Fraction::add(Fraction f)
{
	Fraction result;
	result.denom = denom * f.denom;
	result.numer = numer * f.denom + denom * f.numer;
	result.reduce();
	
	return result;
}

void Fraction::print()
{
	cout << numer << "/" << denom << endl;
}
Fraction operator+(Fraction &f1, Fraction &f2) {
	Fraction result;
	result = f1.add(f2);
	result.reduce();
	
	return result;
}
Fraction operator-(Fraction &f1, Fraction &f2) {
	Fraction result;
	result.denom = f1.denom * f2.denom;
	result.numer = f1.numer * f2.denom - f1.denom * f2.numer;
	result.reduce();
	
	return result;
}
Fraction& Fraction::operator--() {
	numer -= denom;
	reduce();
	
	return *this;
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
	
	Fraction f3; //add
	Fraction f4; //sub
	Fraction f5; //--
	
	cin >> f1 >> f2;
	
	f3 = f1 + f2;
	f4 = f1 - f2;
	
	f3.print();
	f4.print();
	----f2;
	f2.print();
	
	return 0;
}