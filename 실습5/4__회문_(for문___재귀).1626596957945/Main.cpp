#include <iostream>
#include <string>
using namespace std;

bool isPalindrome1(string str)
{
	int length = str.length();
	bool rt = true;
	for(int i=0;i<length/2;i++)
		if(str[i] != str[length -1- i])
			rt = false;
	return rt;
}

bool isPalindrome2(string str)
{
	if (str.length() <= 1)
		return true;
	if(str[0] != str[str.length() - 1])
		return false;
	return isPalindrome2(str.substr(1,str.length() - 2));
}

int main()
{
	string str;
	cin >> str;
	
	cout << isPalindrome1(str) << endl;

	cout << isPalindrome2(str) << endl;
	
	return 0;
}