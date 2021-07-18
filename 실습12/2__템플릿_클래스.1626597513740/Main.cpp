#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class Box {
	T data;
public:
	void set(T data)
	{
		this->data = data;
	}
	T get() 
	{
		return data;
	}
};

int main()
{
	Box<int> b;
	Box<double> b1;

	b.set(20);
	b1.set(20.5);
	cout << b.get() << " " << b1.get() << endl;

	return 0;
}