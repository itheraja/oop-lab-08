#include <iostream>
using namespace std;

class ComplexNumber {
private:
    double real;
    double imag;

public:
    // Constructor
    ComplexNumber(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // Overload + operator
    ComplexNumber operator+(const ComplexNumber& other) {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    // Overload - operator
    ComplexNumber operator-(const ComplexNumber& other) {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    // Overload * operator
    ComplexNumber operator*(const ComplexNumber& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return ComplexNumber(r, i);
    }

    // Overload == operator
    bool operator==(const ComplexNumber& other) {
        return (real == other.real && imag == other.imag);
    }

    // Display function
    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    ComplexNumber c1(3, 4);
    ComplexNumber c2(1, 2);
    ComplexNumber c3(8, 3);
    ComplexNumber c4(5, 6);
    ComplexNumber c5(2, 3);
    ComplexNumber c6(1, 4);

    cout << "Addition: ";
    (c1 + c2).display(); // 3+4i + 1+2i = 4+6i

    cout << "Subtraction: ";
    (c3 - c4).display(); // 8+3i - 5+6i = 3-3i

    cout << "Multiplication: ";
    (c5 * c6).display(); // (2+3i)*(1+4i) = -10+11i

    cout << "Equality Check: ";
    if (ComplexNumber(3, 5) == ComplexNumber(3, 5))
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    if (ComplexNumber(3, 5) == ComplexNumber(4, 5))
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    return 0;
}
