#include <iostream>
#include <vector>
using namespace std;
int findMaxIndex(vector<int> v, int n)
{
	int max = 0;
	for(int i=0;i<n;i++) {
		if(v[max] < v[i])
			max = i;
	}
	return max;
}

void swap(int& a, int& b)
{
	int tmp;
	tmp = b;
	b = a;
	a = tmp;
}

void sort(vector<int> &v)
{
	for(int i=v.size();i>0;i--) {
		int max = findMaxIndex(v, i);
		swap(v[max], v[i-1]);
	}
}

int main()
{
	vector<int> score;
	int n, in_score;
	cin >> n;
	
	
	for (int i = 0; i < n; i++) {
		cin >> in_score;
		score.push_back(in_score);
	}

	sort(score);

	for (int i = 0; i < n; i++)
		cout << score[i] << " ";

	cout << endl;

	return 0;
}