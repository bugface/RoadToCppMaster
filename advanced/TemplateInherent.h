//
// Created by alex on 7/12/22.
//

#ifndef ADVANCED_TEMPLATEINHERENT_H
#define ADVANCED_TEMPLATEINHERENT_H
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Base {
public:
    T m;
};

// when inherent we have to define the typename in the Base class
class Son : public Base<int> {
public:
    void show() {
        cout << this->m << endl;
    }
};

//if we want to make the typename flexible as the base class
template <typename E, class T>
class Son1 : public Base<E> {
public:
    T n;

    Son1() = default;

    void show() {
        cout << this->m << " " << this->n << endl;
    }

    void showOutside();

    // define outside class
    Son1(E e, T t);
};

template <class E, class T>
Son1<E, T>::Son1(E e, T t) {
    this->m = e;
    this->n = t;
}

template <class E, class T>
void Son1<E, T>::showOutside() {
    cout << "show outside" << endl;
    cout << this->m << " " << this->n << endl;
}

void test1() {
    Son s1;
    s1.m = 2;
    s1.show();

    Son1<int, string> s2;
    s2.m = 3;
    s2.n = "test";
    s2.show();

    Son1<string, int> s3("a", 2);
    s3.show();
    s3.showOutside();
}

#endif //ADVANCED_TEMPLATEINHERENT_H
