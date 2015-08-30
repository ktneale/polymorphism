/*
 * Written by Kevin Neale (C) 2015.
 *
 * Example of polymorphism in C++ (operator overloading)
 *
 */
#include <iostream>

using namespace std;

class Fraction
{
    public:
        Fraction(int num=0, int denom=0) : m_num(num), m_denom(denom){};
        ~Fraction(){};
        Fraction& operator+(const Fraction&);

        friend ostream& operator<<(ostream& os, const Fraction& fraction);

    private:
        int m_num;
        int m_denom;
};

Fraction& Fraction::operator+(const Fraction& fraction)
{
    int num = fraction.m_num * this->m_denom + this->m_num * fraction.m_denom;
    int denom =  fraction.m_denom * this->m_denom;
    Fraction result = Fraction(num,denom);
    return result;
}

Fraction& Fraction::operator-(const Fraction& fraction)
{
    int num = fraction.m_num * this->m_denom - this->m_num * fraction.m_denom;
    int denom =  fraction.m_denom * this->m_denom;
    Fraction result = Fraction(num,denom);
    return result;
}

ostream& operator<<(ostream& os, const Fraction& fraction)
{
    os << "Fraction: " << fraction.m_num << "/" << fraction.m_denom << endl;
    return os;
}

int main()
{
    Fraction a = Fraction(1,4);
    Fraction b = Fraction(3,4);
    cout << a << b;

    Fraction c = a+b;
    cout << c;

    //Fraction without supplying constructor arguments.
    Fraction d;
    cout << d;

    return 0;
}
