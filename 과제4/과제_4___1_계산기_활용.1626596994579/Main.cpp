#include <iostream>
using namespace std;

class calculator {
private:
	int value = 0;
	int memoryValue = 0;
	
public:
	int setValue(int n) {
		value = n;
		return value;
	}
	void getValue() {
		cout << value << endl;
	}
	int add(int n) {
		value += n;
		return value;
	}
	int sub(int n) {
		value -= n;
		return value;
	}
	int multiply(int n) {
		value *= n;
		return value;
	}
	int divide(int n) {
		value = value/n;
		return value;
	}
	int mod(int n) {
		value = value%n;
		return value;
	}
	int changeSign() {
		value *= -1;
		return value;
	}
	int clear() {
		value = 0;
		return value;
	}
	int memorySave() {
		memoryValue = value;
		return memoryValue;
	}
	void memoryRead() {
		value = memoryValue;
		cout << value << endl;
	}
	int memoryAdd() {
		memoryValue += value;
		return memoryValue;
	}
	int memorySub() {
		memoryValue -= value;
		return memoryValue;
	}
	int memoryClear() {
		memoryValue = 0;
		return memoryValue;
	}
};

int main() {
	calculator c;
	string command;
	c = calculator();
	int n;
	while (1) {
		cin >> command;
		if(command == "setValue") {
			cin >> n;
			c.setValue(n);
		}
		else if(command == "add") {
			cin >> n;
			c.add(n);
		}
		else if(command == "sub") {
			cin >> n;
			c.sub(n);
		}
		else if(command == "mul") {
			cin >> n;
			c.multiply(n);
		}
		else if(command == "div") {
			cin >> n;
			c.divide(n);
		}
		else if(command == "mod") {
			cin >> n;
			c.mod(n);
		}
		else if(command == "change") {
			c.changeSign();
		}
		else if(command == "clear") {
			c.clear();
		}
		else if(command == "MS") {
			c.memorySave();
		}
		else if(command == "MR") {
			c.memoryRead();
		}
		else if(command == "MPlus") {
			c.memoryAdd();
		}
		else if(command == "MMinus") {
			c.memorySub();
		}
		else if(command == "MC") {
			c.memoryClear();
		}
		else if(command == "result") {
			c.getValue();
		}
		else if(command == "quit") {
			break;
		}
	}
	return 0;
}