#include <stdio.h>

int main()
{

	int a, b;
	scanf("%d %d", &a, &b);

	int gcd, temp_a, temp_b, tmp;
	
	temp_a = a;
	temp_b = b;
	
	while(temp_a%temp_b != 0) {
		//최대공약수 구함
		tmp = temp_a%temp_b;
		temp_a=b;
		temp_b=tmp;
	}
	gcd = temp_b;
	
	temp_a = a/gcd;
	temp_b = b/gcd;
	
	int lcm = gcd*temp_a*temp_b;

	printf("%d", lcm); //lcm변수는 최소공배수
	

	return 0;
}