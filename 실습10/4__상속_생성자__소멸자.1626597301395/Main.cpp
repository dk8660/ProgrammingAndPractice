#include <iostream>
#include <string>
using namespace std;

class animal{

public:
	animal(int x){ cout << "생성자 animal" << endl; }
	~animal(){ cout << "생성자 animal" << endl; }
};

class hamster : public animal{

public:
	hamster(){ cout << "생성자 hamster" << endl; }
	~hamster(){ cout << "생성자 hamster" << endl; }
};


int main() {
	
	hamster hamster1; 

}
