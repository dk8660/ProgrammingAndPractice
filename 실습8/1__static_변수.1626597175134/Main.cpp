#include <iostream>
#include <string>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;
public:
	static int count;
	Car(){
		count+=1;
	}

};
int Car::count = 0;

int main()
{
	Car myCar;	
	cout << myCar.count << endl;	
	Car yourCar;		
	cout << yourCar.count << endl;	
	cout << myCar.count << endl;
	cout << Car::count << endl;	

	return 0;
}