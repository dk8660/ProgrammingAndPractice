#include <stdio.h>
#include <math.h>
#include <string.h>
#define SIZE 100 

typedef struct _Time {
	char type[3]; // am or pm
	int hour;
	int minute;
	int second;
} Time;

int diff(Time t1, Time t2) // t2 - t1
{
	int diffBySeconds;
	int convToSeconds1 = 0, convToSeconds2 = 0; 
	if(t1.type[0] != t2.type[0]) {
		t2.hour += 12;
	}
	convToSeconds1 += t1.hour*3600 + t1.minute*60 + t1.second;
	convToSeconds2 += t2.hour*3600 + t2.minute*60 + t2.second;
	int tmp = convToSeconds2 - convToSeconds1;
	return tmp;
}

int main()
{
	Time t1, t2;
	
	scanf("%s %d %d %d", &t1.type, &t1.hour, &t1.minute, &t1.second);
	
	scanf("%s %d %d %d", &t2.type, &t2.hour, &t2.minute, &t2.second);
	
	int workingTime = diff(t1,t2);
	int hour = 0, minute = 0, second = 0;
	while(workingTime >= 3600) {
		hour++;
		workingTime -= 3600;
	}
	while(workingTime >= 60) {
		minute++;
		workingTime -= 60;
	}
	second = workingTime;
	printf("%d %d %d\n", hour, minute, second);
	
	return 0;
}
