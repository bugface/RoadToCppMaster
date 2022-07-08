//
// Created by Yang,Xi on 7/4/22.
//

#ifndef STAFFMANAGEMENTSYSTEM_MANAGER_H
#define STAFFMANAGEMENTSYSTEM_MANAGER_H

#pragma once
#include "iostream"
#include "string"
#include "fstream"
#include "staff.h"

#define FILENAME "../file/staffFile.txt"

using namespace std;


class managersys {
private:
    int numStaff;
    staff ** staffArray;
    bool isFileEmpty;
    void _init();
    void _getStaffNum();
    void _initStaffArray();

public:
    managersys();
    ~managersys();
    void showMenu();
    static void systemExit();
    void addStaff();
    void saveToFile();
    void showStaffInfo();
};


#endif //STAFFMANAGEMENTSYSTEM_MANAGER_H
