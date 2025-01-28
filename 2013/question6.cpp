#include<iostream>
using namespace std;

class myclass {
public:
	double a, b;
	myclass(double x, double y) {
		a = x;
		b = y;
		cout << "Constructing object ,a= " << a << "b= " << b << endl;

	}
	~myclass() {
		cout << "Destroying object a= " << a << " b= " << b << endl;


	}
	void show_ab() {
		cout << "value of a= " << a << " value of b " << b << endl;

	}
	

};
myclass fun1(myclass ob1) {
	myclass ob2(10, 20);
	ob2.a = ob2.a * ob1.a;
	ob2.b = ob2.b - ob1.b;
	return ob2;
}

int main() {
	myclass obx(1, 2), oby(5, 6);
	obx.show_ab();
	oby.show_ab();
	oby = fun1(obx);
	oby.show_ab();

	return 0;
}
