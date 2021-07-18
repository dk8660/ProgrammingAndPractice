#include <iostream>
#include <vector>
using namespace std;
int findMaxIndex(int s[], int n)
{
	int max = 0;
	for(int i=0;i<n;i++) {
		if(s[max] < s[i])
			max = i;
	}
	return max;
}

void swap(int &a, int &b)
{
	int tmp;
	tmp = b;
	b  = a;
	a = tmp;
}

void sort(int s[], int n)
{
	for(int i=n;i>1;i--) {
		int maxPos = findMaxIndex(s,i);
		swap(s[maxPos],s[i-1]);
	}
}

int main()
{
	int *score;
	int n;
	cin >> n;
	score = new int[n];
	
	for (int i = 0; i < n; i++)
		cin >> score[i];

	sort(score,n);

	for (int i = 0; i < n; i++)
		cout << score[i] << " ";

	cout << endl;

	return 0;
}