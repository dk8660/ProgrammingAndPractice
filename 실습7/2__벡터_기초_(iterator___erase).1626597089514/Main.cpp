#include <vector>
#include <iostream>
using namespace std; 

int main(){
	
	vector<int> v;

	v.push_back(10); // 10
	v.push_back(20); // 10 20
	v.push_back(30); // 10 20 30
	v.push_back(40); // 10 20 30 40
	v.push_back(50); // 10 20 30 40 50
	
	vector<int>::iterator iter;
	iter = v.begin();
	cout << *iter << endl;
	cout << iter[2] << " " << *(iter+2) << endl;
	cout << "-----------------------------" << endl;
	iter = v.end();
	cout << *iter << endl;
	cout << "-----------------------------" << endl;
	
	v.erase(v.begin()+1);
	
	for (iter=v.begin(); iter!=v.end(); ++iter)
		cout << *iter << endl;
	
}