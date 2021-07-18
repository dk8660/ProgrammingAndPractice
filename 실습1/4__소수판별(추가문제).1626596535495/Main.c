#include <stdio.h>

int main()
{
	int n;
	int count=0;
	int isPrime = 0;
	scanf("%d", &n);
	if(n<2)
		count=0;
	else {
		count=1;
		for(int i=3;i<n+1;i++) {
			for(int j=2;j<i;j++) {
				if(i%j==0)
					isPrime++;
			}
			if(isPrime==0)
				count++;
			isPrime = 0;
		}
	}
	printf("%d",count);

	return 0;
}

