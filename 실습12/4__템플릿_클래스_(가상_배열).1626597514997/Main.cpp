#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class VirtualArray {
	T* arr;
	int size;
public:
	VirtualArray(int size = 0) {
		this->size = size;
		arr = new T[size];
	}
	T& operator [] (int i) {
		assert(i < size);
		return arr[i];
	}
};

int main()
{
	int n;
	cin >> n;
	VirtualArray<int> v(n);
	
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	for (int i = 0; i < n; i++)
		cout << v[i] << " " ;
	
	cout << endl;
	VirtualArray<float> t(n);
	
	for (int i = 0; i < n; i++)
		cin >> t[i];
	
	for (int i = 0; i < n; i++)
		cout << t[i] << " " ;

	return 0;
}