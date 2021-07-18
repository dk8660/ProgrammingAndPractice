#include <stdio.h>
int main() {
	int n;
	int result_sum = 0;
	scanf("%d",&n);
	
	// while이나 for문으로 작성
	result_sum += n;
	
	while(n/10 != 0) {
		result_sum += n%10;
		n = n/10;
	}
	result_sum += n;
	
	printf("%d",result_sum);
	
	return 0;
}
