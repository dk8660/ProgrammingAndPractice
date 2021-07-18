#include <stdio.h> // greatest common divisor 
int main()
{
	int a,b;
	int tmp;
	scanf("%d %d", &a, &b);

	while (a % b != 0) {
		tmp = a%b;
		a = b;
		b = tmp;
	}

	printf("%d", b);
			
	return 0;
}
