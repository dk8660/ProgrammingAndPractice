#include <stdio.h>
int jy(int year) {
	if((year%4 == 0) && (year%100 != 0) || (year%400 ==0))
		return 1;
	else
		return 0;
}

int main() {
	int dd, mm, yy;
	
	int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	
	char week[7][4];  // string week[7]  week[0] = "Sun".....
	
	strcpy(week[0], "Sun");
	strcpy(week[1], "Mon");
	strcpy(week[2], "Tue");
	strcpy(week[3], "Wed");
	strcpy(week[4], "Thr");
	strcpy(week[5], "Fri");
	strcpy(week[6], "Sat");
	
	int baseDay = 1;
	int baseMonth = 1;
	int baseYear = 2019;
	int baseWeek = 2;
	
	scanf("%d%d%d",&yy, &mm, &dd);
	int sum = 0;
	int r = 0;
	int term = 0;
	for(int i=2019;i<yy;i++) {
		if(jy(i) == 1)
			term += 366;
		else
			term += 365;
	}
	if(jy(yy) == 1)
		month[2] = 29;
	for(int i=1;i<mm;i++) {
		sum += month[i];
	}
	sum += dd;
	sum += term;
	r = (sum+1) % 7;
	printf("%s\n",week[r]);
}
