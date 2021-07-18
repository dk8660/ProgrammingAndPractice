#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	char name[200][9];      //최대 8글자이하의 알파벳
	int score[200] = {0};//일단 전부 0으로 초기화
	float tmp[200] = {0};
	int n;
	float r = 0;
	scanf("%d",&n);
	
	for (int i=0;i<n;i++){
		scanf("%s %d", name[i] , &score[i]);
	}
	float avr = 0;
	for(int i=0;i<n;i++) {
		avr += score[i];
	}
	avr = avr/n;
	float sum = 0;
	for(int i=0;i<n;i++) {
		tmp[i] = (score[i] - avr)*(score[i] - avr);
		sum += tmp[i];
	}
	r = sqrt(sum/n);
	int tmp_ = 0;
	for(int i=0;i<n;i++)
		tmp[i] = score[i];
	for(int i=0;i<n;i++) {
		for(int j=0;j<n-i-1;j++) {
			if(tmp[j]>tmp[j+1]) {
				tmp_ = tmp[j];
				tmp[j] = tmp[j+1];
				tmp[j+1] = tmp_;
			}
		}
	}
	printf("표준편차 = %.2f\n",r);
	for(int i = 0;i<n;i++) {
		if(score[i] == tmp[n-1])
			printf("%s %d\n",name[i],score[i]);
	}
	return 0;
}