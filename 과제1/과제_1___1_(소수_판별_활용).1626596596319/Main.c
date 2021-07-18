#include <stdio.h>
int main() {
	int n, a, b, count, tmp = 0;
	scanf("%d", &n);
	if (n==4) {
		a = 2;
		b = 2;
	}
	else {
		int i = 3;
		int j = 2;
		for (i; i < n; i++) {
			count = 0;
			for (j = 2; j < i; j++) {
				if (i % j == 0)
					count++;
			}
			if (count == 0) {
				a = i;
				b = n - a;
				i = a + 1;
				for (j = 2; j < b; j++) {
					if (b % j == 0)
						count++;
				}
				if (count == 0) {
					if (i >= n / 2)
						break;
				}
				else
					count = 0;
			}
			else
				count = 0;
		}
	}
	if(a>b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	printf("%d %d\n", a, b);
}