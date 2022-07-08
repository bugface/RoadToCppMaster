//
// Created by Yang,Xi on 6/30/22.
//

#ifndef LEARN_A_H
#define LEARN_A_H

// test operator reload
#include "string"
#include "iostream"

using namespace std;

class A {
    friend ostream & operator<<(ostream & o, A & a);
private:
    int c = -1;

public:
    int a;
    int b;
    int * d = nullptr;

    ~A(){
        if (this->d != nullptr) {
            delete this->d;
            this->d = nullptr;
        }
    }

    A addA(A * aa) {
        A temp;
        temp.a = this->a + aa->a;
        temp.b = this->b + aa->b;
        return temp;
    }

    A operator+(A & aa) const {
        printf("execute class field\n");
        A temp;
        temp.a = this->a + aa.a;
        temp.b = this->b + aa.b;
        return temp;
    }

    A operator+(int i) const {
        printf("execute class field\n");
        A temp;
        temp.a = this->a + i;
        temp.b = this->b + i;
        return temp;
    }

    void show(){
        printf("a is %d; b is %d\n", a, b);
    }

    // reload ++ (two ways ++a and a++)
    // for ++a we return reference
    A & operator++() {
        this->a++;
        return * this;
    }

    // for a++ we return value
    A operator++(int){
        A temp = * this;
        this->a++;
        return temp;
    }

    // = by default is shallow copy
    // when pass parameter for deep copy, pass reference; otherwise it will create a copy
    // which will cause mem leak later
    A & operator=(A & aa) {
        delete this->d;
        this->d = nullptr;
        this->d = new int(* aa.d);
        return * this;
    }

    bool operator==(A & aa ) const {
        return this->a == aa.a && this->b == aa.b;
    }

    bool operator!=(A & aa ) const {
        return this->a != aa.a || this->b != aa.b;
    }
};

A operator+(A & a1, A & a2){
    printf("execute global\n");
    A temp;
    temp.a = a1.a + a2.a;
    temp.b = a1.b + a2.b;
    return temp;
}

ostream & operator<<(ostream & o, A & a) {
    o << a.a << " " << a.b << " " << a.c;
    return o;
}


#endif //LEARN_A_H
