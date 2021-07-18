#include <stdio.h>
int fuc(int n) {
	int sum = 0;
	sum += n;
	while(n/10 != 0) {
		sum += n%10;
		n = n/10;
	}
	sum += n;
	return sum;
}

int main()
{
	int n;
  int gtr = -1; // 생성자 저장용 (만약 생성자가 없는 숫자면 -1이 디폴트)
	int r;
	
  scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		r = fuc(i);
		if(r==n) {
			gtr = i;
			break;
		}
	}
	printf("%d\n", gtr);

  return 0; 	
}
