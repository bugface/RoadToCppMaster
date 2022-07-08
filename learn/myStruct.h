//
// Created by Yang,Xi on 6/18/22.
//
#include <iostream>
using namespace std;

#ifndef LEARN_MYSTRUCT_H
#define LEARN_MYSTRUCT_H

struct MyStruct {
    int score;
    void show() const;
};

struct stu {
    string name;
    int age;
    int score;
};

struct nestStruct {
    int id;
    string name;
    struct stu s;
    void show();
};

struct Std {
    string name;
    int score;
};

struct Teacher {
    string name;
    Std sArr[5];
};

void addTSInfo(Teacher arr[], int len);
void printInfo(Teacher arr[], int len);

#endif //LEARN_MYSTRUCT_H
