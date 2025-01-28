#include <iostream>
using namespace std;

class class1 {
public:
    int dim_a; // Vector size
    float *A;  // Dynamic vector pointer

    // Constructor
    class1(int a) {
        dim_a = a; 
        A = new float[dim_a];
        for (int i = 0; i < dim_a; i++) {
            A[i] = 0.0; // Initialize vector elements to 0
        }
    }

    // Destructor
    ~class1() { 
        delete[] A; 
    }

    // Assignment Operator Overloading
    class1& operator=(const class1 &ob1) {
        // Self-assignment check
        if (this == &ob1) {
            return *this;
        }

        // If sizes are different, reallocate memory
        if (dim_a != ob1.dim_a) {
            delete[] A;           // Free old memory
            dim_a = ob1.dim_a;    // Update size
            A = new float[dim_a]; // Allocate new memory
        }

        // Copy elements
        for (int i = 0; i < dim_a; i++) {
            A[i] = ob1.A[i];
        }

        return *this; // Return the current object
    }

    // Display Function (To Show Vector Elements)
    void display() {
        cout << "Vector: ";
        for (int i = 0; i < dim_a; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    class1 obj1(5); // Create an object with size 5
    for (int i = 0; i < 5; i++) {
        obj1.A[i] = i * 2; // Initialize obj1 vector
    }

    class1 obj2(3); // Create another object with size 3
    obj2 = obj1;    // Use assignment operator

    cout << "Object 1: ";
    obj1.display();

    cout << "Object 2: ";
    obj2.display();

    return 0;
}
