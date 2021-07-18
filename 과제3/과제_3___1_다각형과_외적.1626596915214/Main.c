#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int x;
	int y;
} Point;

int ccw(Point p1, Point p2, Point p3) {
	int s;
	s = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);

	if (s > 0)
		return 1;
	else if (s < 0)
		return -1;
	else
		return 0;
}

int main() {
	int n;
	scanf("%d", &n);

	Point* ptr = (Point *)malloc(sizeof(Point) * n);
	if (ptr == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	
	for (int i = 0; i < n; i++)
		scanf("%d %d", &ptr[i].x, &ptr[i].y);
	int countP = 0, countM = 0;
	for (int i = 0; i < n - 2; i++) {
		if (ccw(ptr[i], ptr[i + 1], ptr[i + 2]) == 1)
			countP++;
		if (ccw(ptr[i], ptr[i + 1], ptr[i + 2]) == -1)
			countM++;
	}
	if (ccw(ptr[n - 2], ptr[n - 1], ptr[0]) == 1)
		countP++;
	if (ccw(ptr[n - 2], ptr[n - 1], ptr[0]) == -1)
		countM++;
	if (ccw(ptr[n - 1], ptr[0], ptr[1]) == 1)
		countP++;
	if (ccw(ptr[n - 1], ptr[0], ptr[1]) == -1)
		countM++;

	if (countP <= countM)
		printf("%d\n", countP);
	else
		printf("%d\n", countM);

	free(ptr);

	return 0;
}