#include <stdio.h>
#include <string.h>
int jy(int year) {
	if((year%4 == 0) && (year%100 != 0) || (year %400 == 0))
		return 1;
	else
		return 0;
}
int main() {
	int dd, mm, yy, n;
	int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	char week[7][4];  // string week[7]  week[0] = "Sun".....
	strcpy(week[0], "Sun");
	strcpy(week[1], "Mon");
	strcpy(week[2], "Tue");
	strcpy(week[3], "Wed");
	strcpy(week[4], "Thr");
	strcpy(week[5], "Fri");
	strcpy(week[6], "Sat");
	scanf("%d %d %d %d",&yy, &mm, &dd, &n);
	
	int tmp = 0;
	if(jy(yy) == 1)
		month[2] = 29;
	else
		month[2] = 29;
	if(dd+n > month[mm]) {
		n = n - (month[mm] - dd + 1);
		mm++;
		if(mm == 13) {
			yy++;
			mm = 1;
		}
		dd = 1;
	}
	while(1) {
		if(jy(yy) == 1)
			month[2] = 29;
		else
			month[2] = 28;
		tmp = month[mm];
		if(n > tmp) {
			mm++;
			n = n - tmp;
			if(mm == 13) {
				mm = 1;
				yy++;
			}
		}
		else {
			if(dd+n > month[mm]) {
				mm++;
				if(mm == 13) {
					mm = 1;
					yy++;
				}
				dd = dd + n - month[mm];
			}
			else
				dd = dd + n;
			printf("%d %d %d\n",yy,mm,dd);
			break;
		}
	}
	int sum, r, term = 0;
	for(int i=2019;i<yy;i++) {
		if(jy(i) == 1)
			term += 366;
		else
			term += 365;
	}
	if(jy(yy) == 1)
		month[2] = 29;
	for(int i=1;i<mm;i++)
		sum += month[i];
	sum = sum + dd + term;
	r = (sum+1) % 7;
	printf("%s\n", week[r]);
	return 0;
}
