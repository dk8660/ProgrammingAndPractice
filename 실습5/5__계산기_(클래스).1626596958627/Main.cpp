#include <iostream>
using namespace std;
class Calculator {
private:
	int value = 0;
public:
	//생성자 만들기
	int add(int a) {
		value += a;
		return value;
	}
	
	int sub(int a) {
		value -= a;
		return value;
	}
	
	int currentValue() {
		cout << value << endl;
		return value;
	}
};

int main()
{
	Calculator c;
	string command;
	c = Calculator();
	int a;
	while (1){
		cin >> command;
		if(command == "add") {
			cin >> a;
			c.add(a);
		}
		else if(command == "sub") {
			cin >> a;
			c.sub(a);
		}
		else if(command == "result") {
			c.currentValue();
		}
		else if(command == "quit") {
			cout << "종료합니다." << endl;
			break;
		}
	}
	return 0;
}
