#include <iostream>
using namespace std;

class Shape {
	int x, y;
public:
	Shape(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
	virtual double area() = 0;
};

class Rectangle : public Shape {
	double width, height;
public:
	Rectangle( double x = 0, double y = 0, double width = 0, double height = 0): Shape(x,y){
		this->width = width;
		this->height = height;	
	}
	void setWidth(double w) {
		width = w;
	}
	void setHeight(double h) {
		height = h;
	}
	double area() {
		return width*height;
	}
};

class Triangle: public Shape {
private: 
	double base, height;
public: 
	Triangle(double x = 0, double y = 0, double base = 0, double height = 0): Shape(x,y){
		this->base = base;
		this->height = height;
	}
	double area() {
		return base*height/2.0;
	}
};

class Circle : public Shape {
private: 
	double radius; 
public: 
	Circle(double x = 0, double y = 0, double radius = 0): Shape(x,y){
		this->radius = radius;
	}
	void setRadius(double r) {
		radius = r;
	}
	double area() {
		return 3.14*radius*radius;
	}
};

int main() 
{
	int n;
	double x, y, width, height, base, radius;
	Shape **shapeArray;
	cin >> n;
	shapeArray = new Shape*[n]; // shapeArray 먼저 동적으로 만들어야함
	
	for (int i = 0; i < n; i++){
		int type;
		cin >> type;
		if (type == 1) {
			cin >> x >> y >> width >> height;
			Rectangle *r = new Rectangle(x,y,width,height);
			shapeArray[i] = r;
		}
		else if (type == 2){
			cin >> x >> y >> base >> height;
			Triangle *t = new Triangle(x,y,base,height);
			shapeArray[i] = t;
		}
		else if (type == 3){
			cin >> x >> y >> radius;
			Circle *c = new Circle(x,y,radius);
			shapeArray[i] = c;
		}
	}
	
	for (int i = 0; i < n; i++){
		cout << shapeArray[i]->area() << endl;
	}
	
	return 0;
}
