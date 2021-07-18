#include <stdio.h>

int Is_prime(int n){
	int count = 0;
	for(int i = 2; i<n; i++) {
		if(n%i == 0)
			count++;
	}
	if(count == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	int count=0;
	int r = 0;
	scanf("%d", &n);
	if(n>=2) {
		count++;
		for(int i = 3; i<=n; i++) {
		r = Is_prime(i);
		if(r==1)
			count++;
		}
	}
	
	
	printf("%d",count);

	return 0;
}

