#include <iostream>
using namespace std;

class B1 {
private:
    int a;
public:
    B1(int x) {
        a = x;
        cout << "Base B1 a=" << a << endl;
    }
    B1() {
        a = 100;
        cout << "Base B1 (no param) a=" << a << endl;
    }
    ~B1() {
        cout << "Destructing B1 a=" << a << endl;
    }
    int geta() {
        return a;
    }
};

class B2 {
private:
    int b;
public:
    B2(int x) {
        b = x;
        cout << "Base B2 b=" << b << endl;
    }
    ~B2() {
        cout << "Destructing B2 b=" << b << endl;
    }
    int getb() {
        return b;
    }
};

class D : public B1, public B2 {
private:
    int c;
public:
    D(int x, int y) : B2(x), B1() {
        c = y;
        cout << "Constructing D (no parameter) c=" << c << endl;
    }
    D(int x, int y, int z) : B2(x), B1(y) {
        c = z;
        cout << "Constructing D c=" << c << endl;
    }
    ~D() {
        cout << "Destructing D c=" << c << endl;
    }
    void show() {
        cout << "a=" << geta() << ", b=" << getb() << ", c=" << c << endl;
    }
};

int main() {
    int i;

    D ob(1, 2, 3);
    D ob1(11, 22);
    ob.show();

    B1 bo1(50);
    cout << "a of bo1=" << bo1.geta() << endl;

    cout << "a of ob=" << ob.geta() << ", b of ob=" << ob.getb();
    cout << endl;

    return 0;
}
