#include <stdio.h>
int main()
{
  int y1 , y2;
  int count = 0;
	
  scanf("%d %d", &y1 , &y2);
	
	//코드를 추가하세요.
	for(y1;y1!=y2+1;y1++) {
		if (y1 % 4 == 0)
			if (y1 % 100 ==0)
				if (y1 % 400 == 0)
					count += 1;
				else
					count += 0;
			else
				count += 1;
	else
		count += 0;
	}
	
	printf("%d",count);
	
  return 0; 	
}
