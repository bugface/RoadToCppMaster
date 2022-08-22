//
// Created by alex on 8/14/22.
//

#ifndef COMPUTERROOMRESERVATION_UTIL_HPP
#define COMPUTERROOMRESERVATION_UTIL_HPP

#pragma once

#include <iostream>
#include "common.hpp"
#include "Identity.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include "Admin.hpp"

using namespace std;

void showMainMenu() {
    cout << "============ Computer Room Reservation System ============" << endl;
    cout << "Select your role:" << endl;
    cout << "1. student" << endl;
    cout << "2. Teacher" << endl;
    cout << "3. Admin" << endl;
    cout << "0. Exit" << endl;
    cout << "===========================================================" << endl;
}

void adminMenu(Identity *&p) {
    while (true) {
        p->operMenu();

        auto admin = (Admin *) p;

        int select = 0;

        cin >> select;

        if (select == 1) {
            cout << "add new user" << endl;
            admin->addUser();
        } else if (select == 2) {
            cout << "check existing users" << endl;
            admin->showUsers();
        } else if (select == 3) {
            cout << "check Computer Room status" << endl;
            admin->showCompRm();
        } else if (select == 4) {
            cout << "clean history orders" << endl;
            admin->cleanHisData();
        } else {
            delete admin;
            cout << "log out" << endl;
            returnInfo();
            return;
        }
    }
}

void studentMenu(Identity *&p) {
    while (true) {
        p->operMenu();

        auto student = (Student *) p;

        int select = 0;

        cin >> select;

        if (select == 1) {
            cout << "Submit Application order for room reservation." << endl;
            student->applyOrder();
        } else if (select == 2) {
            cout << "Show all reservations." << endl;
            student->showOrder();
        } else if (select == 3) {
            cout << "Cancel order for room reservation." << endl;
            student->cancelOrder();
        } else {
            delete student;
            cout << "log out" << endl;
            returnInfo();
            return;
        }
    }
}

void teacherMenu(Identity *&p) {
    while (true) {
        p->operMenu();

        auto teacher = (Teacher *) p;

        int select = 0;

        cin >> select;

        if (select == 1) {
            cout << "show all reservations" << endl;
            teacher->showOrders();
        } else if (select == 2) {
            cout << "valid pending reservations" << endl;
            teacher->validOrders();
        } else {
            delete teacher;
            cout << "log out" << endl;
            returnInfo();
            return;
        }
    }
}

void login(int type, const string &fn) {
    Identity *role = nullptr;

    int iid;
    string name;
    string pwd;

    cout << "Input your ID" << endl;
    cin >> iid;
    cout << "Input your name" << endl;
    cin >> name;
    cout << "Input your password" << endl;
    cin >> pwd;

    MatchObj cur(iid, name, pwd);
    auto v = load_login_info(fn);
    bool valid = login_validation(cur, v);

    if (type == 1 && valid) {
        cout << "Student login authentication passed." << endl;
        role = new Student(iid, name, pwd);
        studentMenu(role);
        return;
    } else if (type == 2 && valid) {
        cout << "Teacher login authentication passed." << endl;
        role = new Teacher(iid, name, pwd);
        teacherMenu(role);
        return;
    } else if (type == 3 && valid) {
        cout << "Admin login authentication passed." << endl;
        role = new Admin(iid, name, pwd);
        adminMenu(role);
        return;
    }

    authFail();
    returnInfo();
}

#endif
