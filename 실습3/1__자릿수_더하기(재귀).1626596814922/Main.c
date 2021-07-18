#include <stdio.h>


int digitSum(int n) {// n 정수 
	if(n/10 != 0)
		return (n%10)+digitSum(n/10);
	else
		return n;
}

int main()
{
	int n;
	int result;
	scanf("%d", &n);
	result = digitSum(n);
	if(result < 0)
		result = -result;
	printf("%d\n", result);

	return 0;
}
