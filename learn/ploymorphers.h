//
// Created by Yang,Xi on 7/2/22.
//

#ifndef LEARN_PLOYMORPHERS_H
#define LEARN_PLOYMORPHERS_H
#include <utility>

#include "string"
#include "iostream"

using namespace std;


class ploymorphers {

};

class Animal{
public:
    virtual void speak() {
        cout << "animal speak" << endl;
    }

    Animal() {
        cout << "animal constructure" << endl;
    }

    virtual ~Animal() {
        cout << "animal deconstructure" << endl;
    }
};

class Cat : public Animal{
    // overwrite virtual function in the base class
public:
    string * name = nullptr;


    Cat(string name) {
        cout << "cat constructure" << endl;
        this->name = new string(move(name));
    }

    ~Cat() {
        cout << "cat deconstructure" << endl;
        delete this->name;
        this->name = nullptr;
    }

    void speak() {
        cout << *this->name << " cat speak" << endl;
    }
};

class Dog : public Animal{
public:
    void speak() override {
        cout << "dog speak" << endl;
    }
};

void doSpeak(Animal &a) {
    // address bonding during compile if not use virtual keywords
    a.speak();
}

#endif //LEARN_PLOYMORPHERS_H
