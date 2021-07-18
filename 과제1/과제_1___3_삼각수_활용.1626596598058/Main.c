#include <stdio.h>
int main() {
	int n,tmp1,tmp2,tmp3,i;
	int t[100] = {0};
	scanf("%d",&n);
	
	for(i = 1;i<100;i++) {/*t[0]은 0*/
		t[i] = i*(i+1)/2;
	}
	for(i=1;i<100;i++) {
		tmp1 = t[i];
		for(int j=1;j<100;j++) {
			tmp2 = t[j];
			tmp3 = n - tmp1 - tmp2;
				for(int k=1;k<100;k++) {
					if(tmp3 == t[k])
						goto OUT1;
					if(i==99 && j==99 && k==99) {
						printf("-1\n");
						goto OUT2;
					}
				}
		}
	}
OUT1:
	printf("%d %d %d\n",tmp1,tmp2,tmp3);
OUT2:
	return 0;
}
