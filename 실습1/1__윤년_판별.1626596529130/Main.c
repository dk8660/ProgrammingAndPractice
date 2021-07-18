#include <stdio.h>
int main()
{
  int yy;
  int isLeap;
	
  scanf("%d", &yy);
// if , else if , else 구조 이용
	if (yy % 4 == 0)
		if (yy % 100 ==0)
			if (yy % 400 == 0)
				isLeap = 1;
			else
				isLeap = 0;
		else
			isLeap = 1;
	else
		isLeap = 0;
	
	
  if (isLeap)
		printf("yes");
  else
		printf("no");
	
  return 0; 	
}
