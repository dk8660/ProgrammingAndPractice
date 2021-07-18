#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

/* greatest common divisor */
int gcd(int a, int b){
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

class Fraction { /* a fraction, numer/denom */
   int numer; /* numerator of fraction */
   int denom; /* denominator of fraction */
public:
	Fraction();
	Fraction(int a, int b); // 
	void readFrac();	
	void reduce();
	void print();
	
	Fraction add(Fraction f);
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
	int tmpn = abs(numer);
	int tmpd = abs(denom);
	int GCD = gcd(tmpn, tmpd);
	numer /= GCD;
	denom /= GCD;
	if(denom < 0) {
		numer *= -1;
		denom *= -1;
	}
}

Fraction Fraction::add(Fraction f)
{
	int GCD = gcd(denom, f.denom);
	int tmpd = denom;
	denom *= f.denom/GCD;
	numer *= f.denom/GCD;
	f.denom *= tmpd/GCD;
	f.numer *= tmpd/GCD;
/*	cout << f.numer << "/" << f.denom << endl;*/
	numer += f.numer;
	reduce();
	f.numer = numer;
	f.denom = denom;
	return f;
}

void Fraction::print()
{
	cout << numer << "/" << denom << endl;
}

int main()
{
	int n,d;
	cin >> n >> d;
	
	Fraction f1(n,d);
	Fraction f2;
	Fraction f3;
	
	f2.readFrac();
	
	f1.print();
	f2.print();
	f3.print();
	
	f3 = f1.add(f2);
	f3.print();
	
	return 0;
}