//
// Created by alex on 8/14/22.
//

#ifndef COMPUTERROOMRESERVATION_ADMIN_HPP
#define COMPUTERROOMRESERVATION_ADMIN_HPP

#include <iostream>
#include <string>
#include "Identity.hpp"
#include "globalFile.h"
#include "CompRm.hpp"

using namespace std;

class Admin : public Identity {
public:
    int aid;
//    vector<Student> vStu;
//    vector<Teacher> vTea;
    vector<CompRm> vComp;

    Admin() = default;

    Admin(int aid, string name, string pwd);

    void operMenu() override;

    static void addUser();

    static void showUsers();

    void showCompRm();

    static void cleanHisData();
};

Admin::Admin(int aid, string name, string pwd) {
    this->aid = aid;
    this->name = move(name);
    this->pwd = move(pwd);

    this->vComp.clear();
    ifstream ifs;
    ifs.open(COMP_RM_FILE, ios::in);
    CompRm cr{};
    while(ifs >> cr.RmID && ifs >> cr.maxCapacity) {
        this->vComp.emplace_back(cr);
    }
    ifs.close();
}

void Admin::operMenu() {
    cout << "Admin:" << this->name << " log in." << endl;
    cout << "1. add new user" << endl;
    cout << "2. list all users" << endl;
    cout << "3. get computer room information" << endl;
    cout << "4. clean all history order information" << endl;
    cout << "0. quit" << endl;
}

void Admin::addUser() {
    cout << "select roles to add:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;

    int select = 0;
    cin >> select;

    ofstream ofs;
    string fn;

    if (select == 1) {
        fn = STUDENT_FILE;
    } else {
        fn = TEACHER_FILE;
    }

    ofs.open(fn, ios::out | ios::app);
    cout << "New user ID: " << endl;
    int id;
    cin >> id;

    auto v = load_login_info(fn);
    if (check_id_collision(id, v)) {
        cout << "The request id: " << id << " is already exist." << endl;
        id = recommend_id(v);
        cout << "Assigned an available new id: " << id << endl;
    }

    cout << "New user name: " << endl;
    string name;
    cin >> name;

    cout << "New user Password: " << endl;
    string pwd;
    cin >> pwd;

    string info = to_string(id) + " " + name + " " + pwd;
    ofs << info << endl;
    ofs.close();

    cout << "user: " + name + " has been added." << endl;

    returnInfo();
}

void Admin::showUsers() {
    cout << "which group you want to show:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;

    int select = 0;
    cin >> select;

    ofstream ofs;
    string fn;

    if (select == 1) {
        fn = STUDENT_FILE;
    } else {
        fn = TEACHER_FILE;
    }
    auto v = load_login_info(fn);
    for(auto &it: v) {
        cout << "ID: " << it.i << " name: " << it.a << endl;
    }

    returnInfo(4);
}

void Admin::showCompRm() {
    cout << "Room number: " + to_string(vComp.size()) << endl;
    for(auto &it: this->vComp) {
        cout << "Rm ID: " << it.RmID << " max capacity: " << it.maxCapacity << endl;
    }

    returnInfo(4);
}

void Admin::cleanHisData() {
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "All orders are cleaned." << endl;
    returnInfo(2);
}

#endif //COMPUTERROOMRESERVATION_ADMIN_HPP
