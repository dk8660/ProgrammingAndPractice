#include <vector>
#include <iostream>
using namespace std; 

int main(){
	
	vector<int> v;
	
	cout << v.size()<<endl;

	v.push_back(10); // 10
	v.push_back(20); // 10 20
	v.push_back(30); // 10 20 30

	cout << v.size() << endl;
	
	for(int i=0; i < v.size(); i++)
		cout << v[i] <<endl; 
	
	v.pop_back();
	
	cout << v.size() << endl;
	
	for(int i=0; i < v.size(); i++)
		cout << v[i] <<endl; 

}