#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
    double real, imag;

public:

    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }

    void show()
    {
        cout << real;

        if (imag >= 0)
            cout << " + " << imag << "i" << endl;
        else
            cout << " - " << -imag << "i" << endl;
    }

    double module()
    {
        return sqrt(real * real + imag * imag);
    }

    Complex operator-(Complex op2);

    bool operator==(Complex op2);

    bool operator<(Complex op2);

    bool operator>(Complex op2);

    Complex operator=(Complex op2);
};

Complex Complex::operator-(Complex op2)
{
    Complex temp;

    temp.real = real - op2.real;
    temp.imag = imag - op2.imag;

    return temp;
}

bool Complex::operator==(Complex op2)
{
    return (real == op2.real && imag == op2.imag);
}

bool Complex::operator<(Complex op2)
{
    return module() < op2.module();
}

bool Complex::operator>(Complex op2)
{
    return module() > op2.module();
}

Complex Complex::operator=(Complex op2)
{
    real = op2.real;
    imag = op2.imag;

    return *this;
}

int main()
{
    Complex ob1(8, 3);
    Complex ob2(2, 1);
    Complex ob3;

    cout << "Комплексне число ob1: ";
    ob1.show();

    cout << "Комплексне число ob2: ";
    ob2.show();

    ob3 = ob1 - ob2;

    cout << endl;
    cout << "Результат віднімання ob1 - ob2: ";
    ob3.show();

    if (ob1 == ob2)
        cout << "ob1 == ob2" << endl;
    else
        cout << "ob1 != ob2" << endl;

    if (ob1 < ob2)
        cout << "ob1 < ob2" << endl;
    else
        cout << "ob1 не менше ob2" << endl;

    if (ob1 > ob2)
        cout << "ob1 > ob2" << endl;
    else
        cout << "ob1 не більше ob2" << endl;

    ob3 = ob1;

    cout << endl;
    cout << "Після присвоювання ob3 = ob1:" << endl;
    ob3.show();
    
}