#include <stdio.h>

typedef struct Date{
	int year;
	int month;
	int day;
} DateType;

int jy(year) {
	if((year%4 == 0)&&(year%100 != 0)||(year%400 == 0))
		return 1;
	else
		return 0;
}

int main() {
	
	int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	
	char week[7][4];  // string week[7]  week[0] = "Sun".....
	
	strcpy(week[0], "Sun");
	strcpy(week[1], "Mon");
	strcpy(week[2], "Tue");
	strcpy(week[3], "Wed");
	strcpy(week[4], "Thr");
	strcpy(week[5], "Fri");
	strcpy(week[6], "Sat");
	
	DateType base = {2019,1,1}; // baseweek : 화요일
	
	DateType input_Date;
	scanf("%d %d %d", &input_Date.year, &input_Date.month, &input_Date.day);
	int sum = 0;
	for(int i=2019;i<input_Date.year;i++) {
		if(jy(i)==1)
			sum += 366;
		else
			sum += 365;
	}
	for(int i=1;i<input_Date.month;i++) {
		if(jy(input_Date.year)==1)
			month[2] = 29;
		else
			month[2] = 28;
		sum += month[i];
	}
	sum += input_Date.day;
	int result = (sum+1)%7;
	printf("%s\n",week[result]);
}
