//
// Created by Yang,Xi on 6/18/22.
//
#include <iostream>
#include "myStruct.h"
using namespace std;

void MyStruct::show() const {
    cout << score << endl;
}

void nestStruct::show() {
    cout << id << " " << name << endl;
    cout << s.name << endl;
}

void addTSInfo(Teacher tarr[], int len) {
    for (int i=0; i<len; ++i) {
        tarr[i].name = "teacher_" + to_string(i + 1) ;
        int ll = cend(tarr[i].sArr) - cbegin(tarr[i].sArr);
        for (int j=0; j<ll; ++j) {
            tarr[i].sArr[j].name = tarr[i].name + "_student_" + to_string(j);
            tarr[i].sArr[j].score = random() % 61 + 40;
        }
    }
}

void printInfo(Teacher tarr[], int len) {
    for (int i=0; i<len; ++i) {
        cout << tarr[i].name << endl;
        int ll = cend(tarr[i].sArr) - cbegin(tarr[i].sArr);
        for (int j=0; j<ll; ++j) {
            cout << "\t" << tarr[i].sArr[j].name << " " << tarr[i].sArr[j].score << endl;
        }
    }
}