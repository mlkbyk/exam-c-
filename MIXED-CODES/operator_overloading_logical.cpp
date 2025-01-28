#include <iostream>
using namespace std;

class coord {
private:
    int x, y; // x ve y koordinatları

public:
    // Varsayılan yapıcı (default constructor)
    coord() {
        x = 0;
        y = 0;
    }

    // Parametreli yapıcı (constructor with parameters)
    coord(int i, int j) {
        x = i;
        y = j;
    }

    // x ve y'yi döndüren bir fonksiyon
    void get_xy(int& i, int& j) {
        i = x;
        j = y;
    }

    // == operatörünün aşırı yüklenmesi
    int operator==(coord ob2) {
        return (x == ob2.x) && (y == ob2.y);
    }

    // && operatörünün aşırı yüklenmesi
    int operator&&(coord ob2) {
        return (x && ob2.x) && (y && ob2.y);
    }
};

// Eşitlik karşılaştırması yapan fonksiyon
void f1(coord o1, coord o2, char* x, char* y) {
    if (o1 == o2)
        cout << x << " and " << y << " are same" << endl;
    else
        cout << x << " and " << y << " are different" << endl;
}

// Mantıksal değerlendirme yapan fonksiyon
void f2(coord o1, coord o2, char* x, char* y) {
    if (o1 && o2)
        cout << x << " && " << y << " is true" << endl;
    else
        cout << x << " && " << y << " is false" << endl;
}

int main() {
    setlocale(LC_ALL, "Turkish");

    // Nesnelerin tanımlanması
    coord o1(10, 20), o2(5, 3), o3(10, 20), o4(0, 10);

    // Eşitlik kontrolü
    f1(o1, o2, "o1", "o2");
    f1(o1, o3, "o1", "o3");

    // Mantıksal değerlendirme
    f2(o1, o2, "o1", "o2");
    f2(o1, o4, "o1", "o4");

    return 0;
}
