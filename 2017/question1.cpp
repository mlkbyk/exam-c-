#include <iostream>
using namespace std;

class myclass {
public:
    double x, y;

    // Parametreli constructor
    myclass(double a, double b) {
        x = a;
        y = b;
        cout << "Constructing, x=" << x << " y=" << y << endl;
    }

    // Copy constructor
    myclass(const myclass &xx) {
        x = xx.x;
        y = xx.y;
        cout << "Copy Constructor. x=" << x << " y=" << y << endl;
    }

    // Destructor
    ~myclass() {
        cout << "Destroying. x=" << x << " y=" << y << endl;
    }

    // show fonksiyonu
    void show() {
        cout << "x=" << x << " y=" << y << endl;
    }
};

// fun1 fonksiyonu
void fun1(myclass ob1) {
    myclass ob(3, 5);
    ob.x = ob.x + ob1.x;
    ob.y = ob.y + ob1.y;
    cout << "x=" << ob.x << " y=" << ob.y << endl;
}

int main() {
    myclass ob1(8, 15);  // ob1 nesnesi oluşturuluyor
    ob1.show();  // ob1 nesnesinin x ve y değerleri gösteriliyor

    fun1(ob1);  // ob1 nesnesi fun1 fonksiyonuna gönderiliyor
    return 0;
}
