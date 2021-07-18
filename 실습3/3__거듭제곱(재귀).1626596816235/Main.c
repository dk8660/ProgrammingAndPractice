#include <stdio.h>
double power1(double x, int n)
{
	if(n == 0)
		return 1;
	else if(n > 0) {
		return x*power1(x, n-1);
	}
}

double power2(double x, int n)
{
	if (n == 0)
		return 1;
	else if (n > 0){
		if (n % 2 == 0){ // n is even
			int temp = power2(x, n/2);
			return temp*temp;
		// return power2(x,n/2)*power2(x,n/2) : inefficent
		}
		else // n is odd
			return x*power2(x, n-1);// 여기 한줄 채워넣으세요.
	}
}

int main()
{
	int n;

	double x;
	
	scanf("%lf %d", &x, &n);
	printf("%.2lf  %.2lf\n", power1(x,n), power2(x,n));		

	return 0;
}