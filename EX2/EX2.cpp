#include <iostream>
#include <cmath>

class Shape {
protected:
	std::string figure;
	double s = 0;
	double bheight = 0;
	double bwidth = 0;
public:
	virtual std::string type() = 0;
	virtual double square() = 0;
	virtual void border() = 0;
	virtual void print(Shape* shape) {
		shape->border();
		std::cout << "Type: " << shape->type() << std::endl;
		std::cout << "Square: " << shape->square() << std::endl;
		std::cout << "Border width: " << shape->bwidth << " height: " << shape->bheight << std::endl;
	}
};

class Triangle : virtual public Shape {
	double a = 0;
	double b = 0;
	double c = 0;

public:
	virtual std::string type() {
		return figure = "Triangle";
	}

	virtual double square() {
		double p = (a + b + c) / 2;
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		return s;
	}

	virtual void border() {
		double p = (a + b + c) / 2;
		bwidth = a* b* c / (4 * sqrt(p * (p - a) * (p - b) * (p - c))) * 2;
		bheight = bwidth;
	}

	Triangle(double inA, double inB, double inC) {
		a = inA;
		b = inB;
		c = inC;
	}
};

class Circle : virtual public Shape {
	double radius = 0;

public:
	virtual std::string type() {
		return figure = "Circle";
	}

	virtual double square() {
		s = atan(1) * 4 * radius;
		return s;
	}

	virtual void border() {
		bwidth = radius * 2;
		bheight = bwidth;
	}

	Circle(double inRadius) {
		radius = inRadius;
	}
};

class Rectangle : virtual public Shape {
	double a = 0;
	double b = 0;

public:
	virtual std::string type() {
		return figure = "Rectangle";
	}

	virtual double square() {
		s = a * b;
		return s;
	}

	virtual void border() {
		bwidth = a;
		bheight = b;
	}

	Rectangle(double inA, double inB) {
		a = inA;
		b = inB;
	}
};

int main() {
	Triangle t(3, 4, 5);
	t.print(&t);
	return 0;
}