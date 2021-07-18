#include <stdio.h>
#include <math.h>  // sqrt
#define SIZE 100 

typedef struct Point {
	float x;
	float y;
} Point;

void movePoint(Point *p, float dx, float dy)
{
	(*p).x += dx; // p->x += dx;
	(*p).y += dy; // p->y += dy;
}

void movePolygon(Point polygon[], int n , float dx , float dy)
{
	for(int i=0;i<n;i++) {
		movePoint(&polygon[i],dx,dy);
	}
}

float dist(Point p, Point q)
{
	return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
// pow	
}


float perimeter(Point polygon[], int n) //
{
	float length = 0;
	for(int i=0;i<n-1;i++){
		length += dist(polygon[i],polygon[i+1]);
	}
	length += dist(polygon[n-1],polygon[0]);
	return length;
}



int main()
{
	int n;
	
	Point polygon[SIZE];
	float dx, dy;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%f%f", &polygon[i].x, &polygon[i].y);
	

	scanf("%f%f", &dx, &dy);
	
//	for (int i = 0; i < n; i++)
//		movePoint(&polygon[i], dx, dy);
	

	movePolygon(polygon, n, dx, dy);

	
	for (int i = 0; i < n; i++)
		printf("(%.2f,%.2f)", polygon[i].x, polygon[i].y);
	
	printf("\n");
	
	printf("%.2f", perimeter(polygon,n));
	
	return 0;
	
}
