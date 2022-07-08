//
// Created by Yang,Xi on 7/2/22.
//

#ifndef LEARN_BASE_H
#define LEARN_BASE_H
#include "string"
#include "iostream"

using namespace std;


class Base {
public:
    int a = 10;

    Base() {cout << "call base constructor" << endl;}
    ~Base() {cout << "call base deconstructor" << endl;}

    void func() {
        cout << "base func" << endl;
    }
};

class Son : public Base{
public:
    int a = 15;
    int b = 20;
    Son() {cout << "call son constructor" << endl;}
    ~Son() {cout << "call son deconstructor" << endl;}

    void func() {
        cout << "son func" << endl;
    }
};

class AA {
public:
    int a = 10;
    int b = 1;
};

// diamond inherent
// use virtual
class B : virtual public AA {
public:
    int a = 11;
};

class C : virtual public AA {
public:
    int a = 12;
};

class D : public B, public C {
public:
    int a = 11;
};


#endif //LEARN_BASE_H
