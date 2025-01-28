#include <iostream>
using namespace std;

class myclass {
public:
	double a, b, c;

	myclass(double x, double y, double z) {
		a = x;
		b = y;
		c = z;
		cout << "Constructing. a= " << a << " b= " << b << "c= " << c << endl;
	}
	myclass(double x) {
		a = 10;
		b = x;
		c = 20;
		cout << "Constucting(with one parameter) a= " << a << " b= " << b << " c= " << c << endl;

	}
	myclass() {
		a = 1;
		b = 2;
		c = 3;
		cout << "Constucting(without parameter) a= " << a << " b= " << b << " c= " << c << endl;

	}
	~myclass() {
		cout << "Destroying. a=" << a << " b= " << b << " c= " << c << endl;
	}
	void show_ab() {
		cout << "a= " << a << " b= " << b << " c= " << c << endl;

	}


};

void fun1(myclass x) {

	myclass ob2(1, 5, 10);
	x.a = x.a + ob2.a;
	x.b = x.b + 2 * ob2.b;
	x.c = x.c + 3 * ob2.c;
	x.show_ab();

}
void fun1(myclass x, myclass y) {
	myclass ob(2, 4, 6);
	ob.show_ab();
	ob.a = x.a - y.a;
	ob.b = x.b + y.b;
	ob.show_ab();
	ob.c = x.c + 2 * y.c;

}
myclass fun3(myclass x) {
	myclass ob2(3, 5, 7);
	x.a = ob2.a + x.a;
	x.b = ob2.b + x.b;
	x.c = ob2.c - x.c;
	return x;

}
myclass fun2(myclass* ob1) {
	myclass ob2(5, 3, 1);
	ob2.a = ob2.a * ob1->a;
	ob2.b = ob2.b * ob1->b;
	ob2.c = ob2.c * ob1->c;
	cout << "Passing by pointer" << endl;
	ob1->a = 1; ob1->b = 3; ob1->c = 4;
	return ob2;
}
int main() {
	myclass ob1, ob2(10, 20, 30);
	fun1(ob1);
	ob1 = fun3(ob2);
	ob1.show_ab();
	ob2.show_ab();
	return 0;

}
