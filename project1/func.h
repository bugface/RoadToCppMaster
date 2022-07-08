//
// Created by Yang,Xi on 6/20/22.
//
#include <iostream>
#include "string"
using namespace std;

#ifndef PROJECT1_FUNC_H
#define PROJECT1_FUNC_H

#define MAX_SIZE 1000

struct User {
    string name;
    int age;
};

struct Book {
    User uList[MAX_SIZE];
    int current_size;
};

void showManu();

void addUser(Book * b);

void showUser(Book * b);

int searchUser(Book * b);

int searchUser(Book * b, string name);

bool deleteUser(Book * b);

bool updateUser(Book * b);

void cleanUp(Book * b);

#endif //PROJECT1_FUNC_H
