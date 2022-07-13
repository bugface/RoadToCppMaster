//
// Created by alex on 7/12/22.
//
#include <iostream>
#include "splitfile.h"

using namespace std;

template <class T>
splitfile<T>::splitfile(T t) {
    cout << "implement in cpp" << endl;
    this->t = t;
}

template <class E>
void splitfile<E>::show() {
    cout << "show implement in cpp" << endl;
    cout << this->t << endl;
}