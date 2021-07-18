#include <stdio.h>
int getgcd(int a, int b) {
	int gcd = 0;
	int tmp = 0;
	while(a%b != 0) {
		tmp = a%b;
		a = b;
		b = tmp;
	}
	gcd = b;
	return gcd;
}
int main()
{

	int a, b;
	scanf("%d %d", &a, &b);

	int gcd;
	gcd = getgcd(a,b);
	int lcm = gcd*(a/gcd)*(b/gcd);

	
	//printf("size of long long = %d\n", sizeof(long long));
	printf("%d", lcm);
	

	return 0;
}