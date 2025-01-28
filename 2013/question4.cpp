#include<iostream>
using namespace std;
class myclass {
public:
	double a, b;
	myclass(double x, double y) {
		a = x;
		b = y;
		cout << "Constructing object a= " << a << " b= " << b << endl;

	}
	myclass() {
		a = 5;
		b = 10;
		cout << "constuctig object(without parameters) a= " << a << " b= " << b << endl;

	}
	~myclass() {
		cout << "Destroying object a= " << a << " b= " << endl;
	}

	void show_ab() {
		cout << "value of a= " << a << " b= " << b << endl;;
	}
};
int main() {
	myclass ob_1(0, 0), ob_2;
	ob_1.show_ab();
	{
		myclass ob_3(20, 50);
	}
	ob_2.show_ab();
	return 0;

	return 0;
}
