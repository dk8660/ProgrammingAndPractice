#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *reverse(char *str)
{
	int length = strlen(str) ;
	char *result;
	
	result = (char *)malloc(sizeof(char)*length);
	for (int i = 0; i < length; i++){
		result[i] = str[length -1 -i];
	}
	
	return result;
}

int main()
{
	
	char str[10];
	
	char *rev_str; 
	
	scanf("%s", str);
	
	rev_str = reverse(str);
	
	printf("%s", rev_str);
	
	return 0;
	
}
