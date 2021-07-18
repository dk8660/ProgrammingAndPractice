#include <stdio.h>
int main() {
	int i;
	long a[100] = {0};
	long b[100] = {0};
	i = 0;
	while(1) {
		scanf("%ld",&a[i]);
		if(a[i] == -1)
			break;
		i++;
	}
	long tmp,gcd,lcm = 0;
	long tmp_a[100] = {0};
	i = 0;
	while(1) {
		tmp_a[i] = a[i];
		tmp_a[i+1] = a[i+1];
		if(tmp_a[i+1] == -1)
			break;
		while(tmp_a[i]%tmp_a[i+1] != 0) {
			tmp = tmp_a[i]%tmp_a[i+1];
			tmp_a[i] = a[i+1];
			tmp_a[i+1] = tmp;
		}
		gcd = tmp_a[i+1];
		tmp_a[i] = a[i]/gcd;
		tmp_a[i+1] = a[i+1]/gcd;
		lcm = gcd*tmp_a[i]*tmp_a[i+1];
		a[i+1] = lcm;
		i++;
		gcd, lcm = 0;
	}
	
	printf("%ld\n",a[i]);
	return 0;
}
