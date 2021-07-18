#include <iostream>
#include <ctype.h>
#include <stdbool.h>

using namespace std;

typedef struct sub{
	int size;
	string str;
}Sub;

int main() {
	string s;
	cin >> s;
	int m=0;
	int length=s.length();
	for(int i=0; i<length; i++){
		if('A'<= s[i] && s[i] <= 'Z'){
			s[i]=tolower(s[i]);
		}
	}
	bool t=true;
	int count=0;
	for(int i=0; i<length;i++) {
		for(int j=length -1; j>=i; j--){
			for (int k = i; k <=(i+j)/2 ; k++) { 
				if (s[k]!=s[j-m]){
					t=false;
				}
				m++;
			}
			if(t==true){
				count++;
			}
			t=true;
			m=0;
		}
	}
	m = 0;
	t = true;
	int index = 0;
	Sub* ptr = (Sub*)malloc(sizeof(Sub) * count);
	if (ptr == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	t = true;
	m = 0;
	for (int i = 0; i < length; i++) {
		for (int j = length - 1; j >= i; j--) {
			int avr = (j + i) / 2;
			for (int k = i; k <= avr; k++) {
				if (s[k] != s[j - m]) {
					t = false;
				}
				m++;
			}
			if (t == true) {
				ptr[index].size = j - i + 1;
				for (int l = i; l < j + 1; l++) {
					ptr[index].str += s[l];
				}
				index++;
			}
			m = 0;
			t = true;
		}
	}
	
	int max=0;
	for(int i=0;i<count;i++){
		if(max < ptr[i].size)
			max = ptr[i].size;
	}
	
	string tmp{"z"};
	for(int i=0;i<count;i++){
		if(max == ptr[i].size){
			if(ptr[i].str < tmp)
				tmp = ptr[i].str;
		}
	}
	cout << max << "\n" << tmp << endl;
	free(ptr);
	return 0;
}