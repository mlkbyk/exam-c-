#include <iostream>
using namespace std;

class myclass {
    int size; // Dizinin boyutu
    int* p;   // Dinamik dizi işaretçisi

public:
    double x, y, z;

    // Constructor
    myclass(int sz) {
        p = new int[sz]; // Dinamik bellek tahsisi
        if (!p)
            exit(1); // Bellek tahsis edilemezse çık
        size = sz;
        for (int i = 0; i < size; i++) // Diziyi doldur
            p[i] = 2 * i;
    }

    ///////////////////İstenen kısım ////////////////////////////
    // Copy Constructor (Kopya Yapıcı)
    myclass(const myclass& obj) {
        size = obj.size;             // Boyutu kopyala
        p = new int[size];           // Yeni bellek ayır
        for (int i = 0; i < size; i++) // Diziyi kopyala
            p[i] = obj.p[i];
        x = obj.x;
        y = obj.y;
        z = obj.z;
    }

    // Destructor
    ~myclass() {
        delete[] p; // Dinamik belleği serbest bırak
    }

    // Bir elemanı döndüren fonksiyon
    int get(int i) {
        return p[i];
    }

    // Dizinin boyutunu döndüren fonksiyon
    int getSize() const {
        return size;
    }
};

// Bir nesneyi by value alarak gösteren fonksiyon
void show(myclass a) {
    cout << "x = " << a.x << endl;
    cout << "y = " << a.y << endl;
    cout << "z = " << a.z << endl;
    cout << "array: ";
    for (int i = 0; i < a.getSize(); i++) // Kopya nesnesinin boyutuna eriş
        cout << a.get(i) << " ";
    cout << endl;
}

int main() {
    myclass obj1(10); // İlk nesne
    obj1.x = 1.0;
    obj1.y = 2.0;
    obj1.z = 3.0;

    show(obj1); // obj1 fonksiyona gönderilir (kopya oluşturulur)

    return 0;
}
