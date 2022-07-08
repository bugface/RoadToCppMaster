//
// Created by Yang,Xi on 7/3/22.
//

#ifndef LEARN_CALC_H
#define LEARN_CALC_H

#include "istream"
#include "string"

using namespace std;

class AbsCalc {
public:
    int a;
    int b;

    //pure virtual function (abstract method in java)
    // then the class AbsCalc is abstract class
    // we cannot create obj of this class
    // the inherent class must rewrite all virtual methods
    virtual int getRes() = 0;

    void getinfo() {
        cout << a << b << endl;
    }
};

class addCalc : public AbsCalc {
public:
    int getRes() override {
        return a + b;
    }
};

class minusCalc : public AbsCalc {
public:
    int getRes() override {
        return a - b;
    }
};

class mulCalc : public AbsCalc {
public:
    int getRes() override {
        return a * b;
    }
};

void testCalc() {
//    AbsCalc * ac = new AbsCalc;

    AbsCalc * ac = new addCalc;
    ac->a = 11;
    ac->b = 1;
    cout << ac->getRes() << endl;
    ac->getinfo();
    delete ac;

    ac = new minusCalc;
    ac->a = 11;
    ac->b = 1;
    cout << ac->getRes() << endl;
    ac->getinfo();
    delete ac;

    ac = new mulCalc;
    ac->a = 11;
    ac->b = 2;
    cout << ac->getRes() << endl;
    ac->getinfo();
    delete ac;
}


#endif //LEARN_CALC_H
