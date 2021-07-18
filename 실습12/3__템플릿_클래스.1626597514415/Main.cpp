#include <iostream>
#include <assert.h>
using namespace std;

template <typename T1, typename T2>
class Box {
	T1 data1;
	T2 data2;
public:
	void set(T1 data1, T2 data2);
	T1 get_first();
	T2 get_second();

};

template <typename T1, typename T2>
void Box<T1,T2>::set(T1 data1, T2 data2)
{
		this->data1 = data1;
		this->data2 = data2;
}
template <typename T1, typename T2>
T1 Box<T1,T2>::get_first()
{
		return data1;
}
template <typename T1, typename T2>
T2 Box<T1,T2>::get_second()
{
		return data2;
}

int main()
{
	Box<int, double> b;
	b.set(10, 10.5);
	cout << b.get_first() << " " << b.get_second() << endl;

	return 0;
}