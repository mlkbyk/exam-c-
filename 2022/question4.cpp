#include <iostream>

class class1 {
public:
    int dim_a;    // Vektörün boyutu
    double *A;    // Dinamik olarak oluşturulan double tipi dizi

    // Constructor: dim_a boyutunda bir dizi oluşturur
    class1(int a) {
        dim_a = a;
        A = new double[dim_a];
    }

    // Destructor: Dinamik belleği serbest bırakır
    ~class1() {
        delete[] A;
    }

    // Atama operatörünün bildirimi
    class1& operator=(const class1 &object_1);

    // Elemanları yazdırmak için bir yardımcı fonksiyon
    void print() const {
        for (int i = 0; i < dim_a; i++) {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }
};

// Atama operatörünün tanımı
class1& class1::operator=(const class1 &object_1) {
    // Self-assignment kontrolü
    if (this == &object_1) {
        return *this;
    }

    // Eğer boyutlar farklıysa eski belleği serbest bırak ve yeni boyutta bellek tahsis et
    if (this->dim_a != object_1.dim_a) {
        delete[] this->A;               // Eski belleği serbest bırak
        this->dim_a = object_1.dim_a;   // Yeni boyutu kopyala
        this->A = new double[this->dim_a]; // Yeni bellek tahsis et
    }

    // Döngü ile elemanları kopyala
    for (int i = 0; i < this->dim_a; i++) {
        this->A[i] = object_1.A[i];
    }

    return *this; // Zincirleme atama için referans döndür
}

int main() {
    // İki nesne oluştur
    class1 obj1(5); // 5 elemanlı bir dizi
    class1 obj2(3); // 3 elemanlı bir dizi

    // obj1'i doldur
    for (int i = 0; i < 5; i++) {
        obj1.A[i] = i + 1; // [1, 2, 3, 4, 5]
    }

    // obj2'yi doldur
    for (int i = 0; i < 3; i++) {
        obj2.A[i] = (i + 1) * 10; // [10, 20, 30]
    }

    // obj1'i obj2'ye ata
    obj2 = obj1;

    // Sonuçları yazdır
    std::cout << "obj1: ";
    obj1.print();

    std::cout << "obj2: ";
    obj2.print();

    return 0;
}
