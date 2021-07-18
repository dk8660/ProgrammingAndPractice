#include <iostream>
#include <vector>
using namespace std;

void sum(vector<int> v, int n){
// (1)	
	int s = 0;
	for (int i = 0; i < n; i++)
		s += v[i];

	cout << "method 1: " << s << endl;

}

void sum2(vector<int> v, int n){
// (2)iterator
	vector<int>::iterator iter;
	iter = v.begin();
	int s = 0;
	for(int i=0;i<n;i++)
		s += iter[i];
	cout << "method 2: " << s << endl;
}

int main()
{
	vector<int> score;
	int n;
	int mark; 
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> mark;
		score.push_back(mark);
	}
	
	sum(score, n);
	sum2(score, n);
}