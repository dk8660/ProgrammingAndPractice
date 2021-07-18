#include <iostream>
using namespace std;

class Adder {
protected:
	int add(int a, int b) {
		return a + b;
	}
};
class Subtractor {
protected:
	int minus(int a, int b) {
		return a - b;
	}
};

// 다중 상속
class Calculator : public Adder, public Subtractor {
public:
	int calc(char op, int a, int b);
};

int Calculator::calc(char op, int a, int b) {
	int res=0;
	switch(op) {
		case '+' : res = add(a, b); break;
		case '-' : res = minus(a, b); break;
	}
	return res;
}

int main() {
	Calculator handCalculator;
	
	int a,b;
	
	cin >> a >> b;
	
	cout << handCalculator.calc('+', a, b) << endl;
	cout << handCalculator.calc('-', a, b) << endl;
}

