#include <stdio.h>
int main()
{
	int n;
  int gtr = -1; // 생성자 저장용 (만약 생성자가 없는 숫자면 -1이 디폴트)
	
	
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
		int s = 0; //s는 i의 분해합을 저장할 변수
		int m = i;
		s += m;
		while(m/10 != 0) {
			s += m%10;
			m = m/10;
		}
		s += m;
		
		if (s == n) {
			gtr = i;
			break;
		}
	}
  printf("%d\n", gtr);
  return 0; 	
}
