//
// Created by Yang,Xi on 6/20/22.
//

#include <iostream>
#include <stdio.h>
#include "func.h"

using namespace std;

void showManu() {
    printf("1. add user\n");
    printf("2. show users\n");
    printf("3. delete user\n");
    printf("4. search user\n");
    printf("5. modify user\n");
    printf("6. clean up\n");
    printf("0. exist\n");
}

void printUser(User * u) {
    printf("user name: %s; age: %d\n", u->name.c_str(), u->age);
}

void addUser(Book * b) {
    if (b->current_size == MAX_SIZE) {
        printf("reached max 1000 users size.\n");
    } else {
        printf("input user name, age;\n");
        string name;
        int age;
        cin >> name;
        cin >> age;

        User u = {name, age};
        b->uList[b->current_size] = u;

        printf("success adding user\n");
        printUser(&b->uList[b->current_size]);

        b->current_size++;
    }
}

void showUser(Book * b) {
    if (b->current_size == 0) {
        printf("empty book. \n");
    } else {
        for (int i=0; i<b->current_size; ++i) {
            printUser(&b->uList[i]);
        }
    }
}

int searchUser(Book * b, string name) {
    for (int i=0; i<b->current_size; ++i){
        if (b->uList[i].name == name) {
            return i;
        }
    }

    printf("user %s is not in book.", name.c_str());
    return -1;
}

int searchUser(Book * b) {
    printf("input name for delete:\n");
    string name;
    cin >> name;
    int index = searchUser(b, name);
    if (index == -1) {
        printf("user %s is not in book.\n", name.c_str());
    } else {
        User u = b->uList[index];
        printf("find user %s and age is %d.\n", u.name.c_str(), u.age);
    }
    return index;
}

bool deleteUser(Book * b) {
    printf("input name for delete:\n");
    string name;
    cin >> name;
    int index = searchUser(b, name);
    if (index == -1) {
        printf("user %s is not in book.\n", name.c_str());
        return false;
    } else {
        for (int i=index; i<b->current_size; ++i) {
            b->uList[i] = b->uList[i + 1];
        }
        b->current_size--;
        printf("successfully delete %", name.c_str());
    }
}

bool updateUser(Book * b) {
    printf("input name for update:\n");
    string name;
    cin >> name;
    int index = searchUser(b, name);
    if (index == -1) {
        printf("user %s is not in book.\n", name.c_str());
        return false;
    } else {
        printf("input new age info\n");
        int age;
        cin >> age;

        while (! cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("input new age info\n");
            cin >> age;
        }

        b->uList[index].age = age;

        return true;
    }
}

void cleanUp(Book * b) {
    b->current_size = 0;
}