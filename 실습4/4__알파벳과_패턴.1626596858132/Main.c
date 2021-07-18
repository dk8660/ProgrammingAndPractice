#include <stdio.h>
#include <ctype.h>
#include <string.h>
int countAlphabet(char str1[]){
	int cnt = 0;
	for (int i = 0; i < strlen(str1); i++){
		if (isalpha(str1[i]) != 0) // 
			cnt++;
	}
	
	return cnt;
}
// 텍스트 문자열에서 패턴 문자열(substring)이 나오는 횟수 구하기 
// strlen 함수 사용 
int findPattern(char text[], char pattern[]){
	// 
	int cnt = 0;
	int length = strlen(pattern);
	int j = 0;
	for (int i = 0; i < strlen(text); i++){
		// text[i]에서 시작하는 pattern이 있는지 check
		if(pattern[j] == text[i]) {
			j++;
				if(j == length) {
					cnt++;
					j = 0;
				}
		}
	} 	
	return cnt;
}

int main(){
	
	char text[50];
	char pattern[10];
	
	scanf("%s %s", text, pattern);
	
	printf("%d\n", countAlphabet(text));
	printf("%d\n", findPattern(text,pattern));
	
}
