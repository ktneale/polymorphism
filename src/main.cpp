/*
 * Written by Kevin Neale (C) 2015.
 *
 * Example of polymorphism in C++
 *
 */
#include <iostream>

using namespace std;

//Example of operator overloading.
class Fraction {
  public:
  Fraction(int num = 0, int denom = 0):m_num(num), m_denom(denom) {};
    ~Fraction() {};
    Fraction & operator+(const Fraction &);
    Fraction & operator-(const Fraction &);
    friend ostream & operator<<(ostream & os, const Fraction & fraction);
    bool operator==(const Fraction & a);

  private:
    int m_num;
    int m_denom;
};

Fraction & Fraction::operator+(const Fraction & fraction)
{
    int num = fraction.m_num * this->m_denom + this->m_num * fraction.m_denom;
    int denom = fraction.m_denom * this->m_denom;
    Fraction result = Fraction(num, denom);
    return result;
}

Fraction & Fraction::operator-(const Fraction & fraction)
{
    int num = fraction.m_num * this->m_denom - this->m_num * fraction.m_denom;
    int denom = fraction.m_denom * this->m_denom;
    Fraction result = Fraction(num, denom);
    return result;
}

bool Fraction::operator==(const Fraction & a)
{
    return (a.m_num == this->m_num && a.m_denom == this->m_denom);
}

ostream & operator<<(ostream & os, const Fraction & fraction)
{
    os << "Fraction: " << fraction.m_num << "/" << fraction.m_denom << endl;
    return os;
}

void operator_overloading_test()
{
    Fraction a = Fraction(1, 4);
    Fraction b = Fraction(3, 4);
    cout << a << b;

    Fraction c = a + b;
    cout << c;

    Fraction d;
    cout << d;

    Fraction e = Fraction(3, 4);

    bool ret;
    ret = e == a;
    cout << ret << endl;

    ret = e == b;
    cout << ret << endl;
}

//Example of virtual functions and member function overloading.
class Mammal {
  public:
    Mammal():m_age(0), m_weight(0) {};
    virtual ~ Mammal() {};                          //Virtual destructor
    virtual void Speak() {};

  protected:
    int m_age;
    int m_weight;
};

class Cat:public Mammal {
  public:
    void Speak() {
        cout << "Meow!\n";
    };
    void Climb() {
        cout << "Climb!\n";
    };
};

class Dog:public Mammal {
  public:
    Dog() {
        m_data = new int[1000];
    };
    ~Dog() {
        delete[]m_data;
    };
    void Speak() {
        cout << "Woof!\n";
    };
    void WagTail() {
        cout << "Tail wag!\n";
    };
    void WagTail(int n);        //Member function overloading

  private:
    int *m_data;                //Used to demonstrate memory leak.
};

void Dog::WagTail(int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
        cout << "Tail wag!\n";

    return;
}

void virtual_function_test()
{
    Cat *felix = new Cat();
    felix->Speak();
    felix->Climb();
    delete felix;

    Dog *spike = new Dog();
    spike->WagTail(3);
    delete spike;

    //Example of base pointer to derived class
    Mammal *fenton = new Dog();
    fenton->Speak();

    delete fenton;
    return;
}


int main()
{
    operator_overloading_test();
    virtual_function_test();
    return 0;
}
