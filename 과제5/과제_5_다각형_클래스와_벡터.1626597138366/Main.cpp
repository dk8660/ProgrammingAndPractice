#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Point {
public:
	int x;
	int y;

	void getPoint(int n, int m) {
		x = n;
		y = m;
	}
	int putx() {
		return x;
	}
	int puty() {
		return y;
	}
};
int ccw(Point p1, Point p2, Point p3) {//오목점 판별을 위한 함수
	int s;
	s = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);

	if (s > 0)
		return 1;
	else if (s < 0)
		return -1;
	else
		return 0;
}
int ccw_(Point p1, Point p2, Point p3) {//ccw함수에서 s의 값이 필요하여 만든 함수
	int s;
	s = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
	return s;
}
float dist(Point p, Point q) {//변의 길이를 구하는 함수
	return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}

class Polygon {
public:
	vector<Point> p;

	int fuc1(vector<Point> p) {//오목점의 개수를 세는 함수
		int countP = 0, countM = 0;
		int n = p.size();
		for (int i = 0; i < n - 2; i++) {
			if (ccw(p[i], p[i + 1], p[i + 2]) == 1)
				countP++;
			if (ccw(p[i], p[i + 1], p[i + 2]) == -1)
				countM++;
		}
		if (ccw(p[n - 2], p[n - 1], p[0]) == 1)
			countP++;
		if (ccw(p[n - 2], p[n - 1], p[0]) == -1)
			countM++;
		if (ccw(p[n - 1], p[0], p[1]) == 1)
			countP++;
		if (ccw(p[n - 1], p[0], p[1]) == -1)
			countM++;
		if (countP <= countM)
			return countP;
		else
			return countM;
	}
	float perimeter(vector<Point> p) {//다각형의 둘레를 구하는 함수
		int n = p.size();
		float length = 0;
		for(int i=0;i<n-1;i++){
			length += dist(p[i],p[i+1]);
		}
		length += dist(p[n-1],p[0]);
		return length;
	}
	float area(vector<Point> p) {//삼각형을 이용하여 다각형의 넓이를 구하는 함수
		int n = p.size();
		float sum = 0;
		for(int i=0;i<n-1;i++)
			sum += ccw_(p[0],p[i],p[i+1]);
		if(sum < 0)
			sum *= -1;
		return sum/2;
	}
};

int main() {
	int n;
	cin >> n;
	int px, py;
	Polygon po;
	Point poi;
	for(int i=0;i<n;i++) {
		cin >> px >> py;
		poi.getPoint(px, py);//벡터에 점의 좌표를 저장하는 식
		po.p.push_back(poi);
	}
	cout << fixed;
	cout.precision(1);
	cout << po.fuc1(po.p) << "\n" << po.perimeter(po.p) << "\n" << po.area(po.p) << endl;
	return 0;
}