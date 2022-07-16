//
// Created by alex on 7/13/22.
//

#ifndef TESTSTL_TESTVECTOR_H
#define TESTSTL_TESTVECTOR_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class testvector {
public:
    string name;
    int age;

    testvector(string n, int a) {
        this->name = move(n);
        this->age = a;
    }
};

void test1();
void test2();
void test3();
void test4();

#endif //TESTSTL_TESTVECTOR_H
