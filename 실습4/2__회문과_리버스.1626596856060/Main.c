#include <stdio.h>
#include <string.h> // strlen, strcpy, strcmp


// 문자열이 palindrome(회문)인가? 
int isPalindrome(char str1[])
{
	int length = strlen(str1);
	for (int i = 0; i < length; i++) {       // 회문1
		
		if (str1[i] != str1[length -1 -i])                            // 회문2
			return 0;
	}
	return 1;
}

void reverse1(char str1[]){
	int length = strlen(str1);
	char tmp;
	for(int i = 0; i < length/2 ; i++) {
		tmp = str1[i];
		str1[i] = str1[length -1 -i];
		str1[length -1 -i] = tmp;
	}
}

void reverse2(char str1[], char str2[]){
	int length = strlen(str1);
	for(int i = 0; i < length; i++){
		str2[i] = str1[length-i-1];
	}	
	
	str2[length] = '\0';	
}



int main()
{
	char str[20];            //회문인지 아닌지 검사할 문자열저장
	char rev_str[20];        //리버스할 문자열 저장
	char return_str[20];
	
	scanf("%s", str);
	scanf("%s", rev_str);
	
	if (isPalindrome(str)==1)
		printf("yes\n");
	else
		printf("no\n");
	
	
	reverse1(rev_str);
	reverse2(rev_str , return_str);
	
	printf("%s\n",rev_str);
	printf("%s\n",return_str);
	
	
	
	
	return 0;
	
}
