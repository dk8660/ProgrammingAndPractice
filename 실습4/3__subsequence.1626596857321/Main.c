#include <stdio.h>
//문자열 s가 문자열 t의 subsequence인가?
 
int isSubsequence(char s[], char t[]) 
{
	int length = strlen(t);
	int length2 = strlen(s);
	int i = 0;
	while(1) {
		for(int j=0;j<length2;j++) {
			if(t[i] == s[j]) {
				i++;
			}
		}
		if(i == length) {
			return 1;
		}
		else
			return 0;
	}
}

int main(){
	char s[20];
	char t[20];
	
	scanf("%s %s",s,t);

	if (isSubsequence(s,t) == 1)
		printf("yes\n");
	else
		printf("no\n");
}
