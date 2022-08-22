//
// Created by alex on 8/14/22.
//

#ifndef COMPUTERROOMRESERVATION_TEACHER_HPP
#define COMPUTERROOMRESERVATION_TEACHER_HPP

#pragma once

#include "Identity.hpp"
#include <string>
#include <iostream>

using namespace std;

class Teacher : public Identity {
public:
    int tid;

    Teacher() = default;

    Teacher(int tid, string name, string pwd);

    void operMenu() override;

    void showOrders();

    static void validOrders();

    map<string, string> d = {
            {"1",  "under reviewing"},
            {"2",  "Reservation granted"},
            {"-1", "Reservation reject"},
            {"0",  "order canceled"},
    };
};


Teacher::Teacher(int tid, string name, string pwd) {
    this->tid = tid;
    this->name = move(name);
    this->pwd = move(pwd);
}

void Teacher::operMenu() {
    cout << "Welcome Teacher: " << this->name << endl;
    cout << "1. check all orders" << endl;
    cout << "2. valid pending orders" << endl;
    cout << "0. exit" << endl;
}

void Teacher::showOrders() {
    Order o;
    if (o.mSize == 0) {
        cout << "No order yet" << endl;
        returnInfo(3);
        return;
    }

    for (auto &it: o.orderData) {
        cout << "Order ID:" << it.first << endl;
        auto info = it.second;
        cout << "student name: " << info["stuName"] << endl;
        cout << "student ID: " << info["stuID"] << endl;
        cout << "date: " << info["date"] << endl;
        cout << "interval: " << (info["interval"] == "1" ? "AM" : "PM") << endl;
        cout << "room: " << info["room"] << endl;
        cout << "status: " << this->d[info["status"]] << endl;

        cout << endl;
    }
}

void Teacher::validOrders() {
    Order o;
    if (o.mSize == 0) {
        cout << "No order yet" << endl;
        returnInfo(3);
        return;
    }

    vector<int> pendingOrderIdx;

    for (auto &it: o.orderData) {
        auto info = it.second;
        if (info["status"] == "1") {
            pendingOrderIdx.push_back(it.first);
            cout << "pending order: " << it.first << endl;
            cout << "student name: " << info["stuName"] << endl;
            cout << "student ID: " << info["stuID"] << endl;
            cout << "date: " << info["date"] << endl;
            cout << "interval: " << (info["interval"] == "1" ? "AM" : "PM") << endl;
            cout << "room: " << info["room"] << endl;
            cout << endl;
        }
    }

    cout << "which order to valid (";
    for (auto it: pendingOrderIdx) {
        cout << it << " ";
    }
    cout << "):" << endl;

    int orderId;
    cin >> orderId;

    if (find(pendingOrderIdx.begin(), pendingOrderIdx.end(), orderId) ==
        pendingOrderIdx.end()) {
        cout << "order ID: " << orderId << " is not a pending order.";
        returnInfo();
        return;
    }

    cout << "Input validation results (2 for approve; -1 for reject): ";
    int res;
    while (true) {
        cin >> res;
        if (res == 2 || res == -1) {
            o.orderData.at(orderId).at("status") = to_string(res);
            o.updateOrder();
            cout << "Order validation done." << endl;
            returnInfo(2);
            break;
        }

        cout << "input is not valid (use 2 or -1)" << endl;
    }
}


#endif //COMPUTERROOMRESERVATION_TEACHER_HPP
