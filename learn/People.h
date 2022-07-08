//
// Created by Yang,Xi on 6/25/22.
//

#ifndef LEARN_PEOPLE_H
#define LEARN_PEOPLE_H
#include "string"
#include "istream"

using namespace std;

class People {
private:
    string name;
    int age;

public:
    People () {}
    People (int age) {this->age = age;}
    People(string name, int age) {this->name = name; this->age = age;}
    // copy generator
    People(const People & p) {
        this->age = p.age;
        this->name = p.name;
    }

    void show() {
        printf("this persion name is %s and age is %d\n", name.c_str(), age);
    }
};


#endif //LEARN_PEOPLE_H
