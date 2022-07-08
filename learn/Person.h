//
// Created by Yang,Xi on 6/26/22.
//

#ifndef LEARN_PERSON_H
#define LEARN_PERSON_H
#include "istream"
#include "string"

using namespace std;


class Person {
public:
    // static declare here but init outside the class
    // static variable shared by all objects created from this class
    static int height;
    string name;
    int *age;

//    Person(){}

//    Person(string name, int age){
//        this->name = name;
//        this->age = new int(age);
//    }

    // field init
    Person(): name("default"), age(new int(0)) {}

    Person(string name, int age): name(move(name)), age(new int(age)){}

    // deep copy
    Person(const Person &p){
        this->name = p.name;
        this->age = new int(* p.age);
    }

    ~Person(){
        // release data allocate in heap
        delete this->age;
        this->age = nullptr;
    }

    static void show() {
        printf("this is a static function and can only used static variable %d \n", height);
//        printf("%s", name) cannot use name since the function is static
    }
};

// init static variable
int Person::height = 10;

class CSum{
public:
    int base;
    mutable int adv;

    CSum & csum(CSum & cs) {
        this->base += cs.base;
        return *this; // return current object self
    }

    void show() {
        printf("this is show function\n");
    }

    void showBase() {
        if (this == nullptr) return;
        printf("base is %d\n", this->base);
    }

    void testConst(int base, int adv) {
        this->base = base;
        this->adv = adv;
        printf("base is %d\n", this->base);
        printf("adv is %d\n", this->adv);
    }

    void testConst(int adv) const {
//        this.base = 10;
        // we cannot modify base in function with const
        // this pointer is a pointer const, Person * const this;  we cannot modify which this point to
        // if we add const here before {}, it equals "const Person * const this"
        // so we cannot modify this pointer and its value
        printf("base is %d\n", this->base);

        // if we want to modify a value this point to
        // we need a keyword "mutable" to the variable we define
        this->adv = adv;
        printf("adv is %d\n", this->adv);
    }
};

#endif //LEARN_PERSON_H
