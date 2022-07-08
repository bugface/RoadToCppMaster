//
// Created by Yang,Xi on 6/24/22.
//

#ifndef LEARN_STUDENT_H
#define LEARN_STUDENT_H

#include "istream"
#include "string"

using namespace std;


class Student {
private:
    string name;
    int id;

public:
    string getName() const {
        return name;
    }

    void setName(const string name) {
        Student::name = name;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Student::id = id;
    }

    void showInfo() {
        printf("student name: %s; student ID: %d", name.c_str(), id);
    }
};


#endif //LEARN_STUDENT_H
