#include <stdio.h>
int main() {
	int answers[100] = {0};  // 정답 배열 
	int points[100] = {0};   // 점수 배열 
	int st_answers[100] = {0}; // 학생 답 배열 
	int sum[100] = {0};
	int n,m,tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&answers[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&points[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			scanf("%d",&st_answers[j]);
		}
		for(int j=0;j<n;j++) {
			if(answers[j] == st_answers[j]) {
				sum[i] += points[j];
			}
		}
	}
	tmp = 0;
	for(int i=0;i<m;i++) {
		if(sum[i] > tmp)
			tmp = sum[i];
	}
	printf("%d\n",tmp);
	return 0;
}
