//
// Created by alex on 8/14/22.
//

#ifndef COMPUTERROOMRESERVATION_STUDENT_HPP
#define COMPUTERROOMRESERVATION_STUDENT_HPP

#include <string>
#include <vector>
#include "Identity.hpp"
#include "globalFile.h"
#include "CompRm.hpp"
#include "Order.hpp"

class Student : public Identity {
public:
    int sid;
    vector<CompRm> vComp;

    Student() = default;

    Student(int sid, string name, string pwd);

    void operMenu() override;

    void applyOrder();

    void showOrder();

    void cancelOrder();

    map<string, string> d = {
            {"1",  "under reviewing"},
            {"2",  "Reservation granted"},
            {"-1", "Reservation reject"},
            {"0",  "order canceled"},
    };
};

Student::Student(int sid, string name, string pwd) {
    this->sid = sid;
    this->name = move(name);
    this->pwd = move(pwd);

    ifstream ifs;
    ifs.open(COMP_RM_FILE, ios::in);
    CompRm cr{};
    while (ifs >> cr.RmID && ifs >> cr.maxCapacity) {
        this->vComp.emplace_back(cr);
    }
    ifs.close();
}

void Student::operMenu() {
    cout << "1. make reservation" << endl;
    cout << "2. show reservation" << endl;
    cout << "3. cancel reservation" << endl;
    cout << "0. quit" << endl;
}

void Student::applyOrder() {
    cout << "selection: 1. Mon.; 2 Tue.; 3 Wed.; 4. Thur.; 5.Fri" << endl;
    int date = 0;
    int interval = 0;
    int room = 0;

    while (true) {
        cin >> date;
        if (date > 0 && date < 6) break;
        cout << "selection must be 1-5" << endl;
    }

    cout << "selection: 1 AM; 2 PM" << endl;
    while (true) {
        cin >> interval;
        if (interval == 1 || interval == 2) break;
        cout << "selection must be 1 or 2" << endl;
    }

    cout << "selection room: 1, 2, or 3" << endl;
    cout << "room capacity: " << endl;
    for (auto &it: this->vComp) {
        cout << "room: " << it.RmID << " capacity: " << it.maxCapacity << endl;
    }

    while (true) {
        cin >> room;
        if (room == 1 || room == 2 || room == 3) break;
        cout << "selection must be 1 or 2" << endl;
    }

    cout << "reservation success. Wait for review." << endl;
    cout << "date: " << date << endl;
    cout << "interval: " << interval << endl;
    cout << "room: " << room << endl;

    ofstream ofs(ORDER_FILE, ios::app);
    ofs << "stuID:" << this->sid << " ";
    ofs << "stuName:" << this->name << " ";
    ofs << "status:" << 1 << " ";
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "room:" << room << endl;
    ofs.close();

    returnInfo();
}

void Student::showOrder() {
    Order o;
    if (o.mSize == 0) {
        cout << "No order in system yet." << endl;
        returnInfo();
        return;
    }

    for (const auto &each: o.orderData) {
        auto info = each.second;
        if (info["stuID"] == to_string(this->sid) && info["stuName"] == this->name) {
            cout << "Order ID:" << each.first << endl;
            cout << "date: " << info["date"] << endl;
            cout << "interval: " << (info["interval"] == "1" ? "AM" : "PM") << endl;
            cout << "room: " << info["room"] << endl;
            cout << "status: " << this->d[info["status"]] << endl;
        }
    }
}

void Student::cancelOrder() {
    Order o;
    if (o.mSize == 0) {
        cout << "No order in system yet." << endl;
        returnInfo();
        return;
    }

    cout << "only cancel orders those are under review or success." << endl;

    vector<int> toCancel;
    int idx = 0;

    for (const auto &each: o.orderData) {
        auto info = each.second;
        if (info["stuID"] == to_string(this->sid) &&
            info["stuName"] == this->name &&
            (info["status"] == "1" || info["status"] == "2")) {
            toCancel.push_back(idx);

            cout << "Order ID:" << idx << " ";
            cout << "date: " << info["date"] << " ";
            cout << "interval: " << (info["interval"] == "1" ? "AM" : "PM") << " ";
            cout << "room: " << info["room"] << endl;
        }
        idx++;
    }

    int select = -1;
    cout << "which order you want to cancel: (";
    for(auto it: toCancel) {
        cout << it << " ";
    }
    cout << ")" <<  endl;

    cin >> select;
    if (find(toCancel.begin(), toCancel.end(), select) != toCancel.end()) {
        o.orderData.erase(select);
        cout << "Order canceled." << endl;
        o.updateOrder();
        o.mSize--;
    } else {
        cout << "No order is associated with you input. No cancel executed." << endl;
    }
}


#endif //COMPUTERROOMRESERVATION_STUDENT_HPP
