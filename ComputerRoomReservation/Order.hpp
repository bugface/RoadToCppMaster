//
// Created by alex on 8/20/22.
//

#ifndef COMPUTERROOMRESERVATION_ORDER_HPP
#define COMPUTERROOMRESERVATION_ORDER_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "globalFile.h"

using namespace std;

class Order {
public:
    int mSize = 0;

    map<int, map<string, string>> orderData;

    Order();

    static void _create_map(const string& element, map<string, string> &m);

    void updateOrder();
};

void Order::_create_map(const string& element, map<string, string> &m) {
    unsigned long pos = element.find(':');

    if (pos == -1) m.insert(make_pair("", ""));

    string k = element.substr(0, pos);
    string v = element.substr(pos + 1, element.size() - pos);

    m.insert(make_pair(k, v));
}

Order::Order() {
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);
    //stuID:1 stuName:alex status:1 date:3 interval:1 room:2
    string sID;
    string sName;
    string status;
    string date;
    string interval;
    string room;

    while (ifs >> sID && ifs >> sName &&
           ifs >> status && ifs >> date && ifs >> interval
           && ifs >> room) {

        map<string, string> line;
        this->_create_map(sID, line);
        this->_create_map(sName, line);
        this->_create_map(status, line);
        this->_create_map(date, line);
        this->_create_map(interval, line);
        this->_create_map(room, line);

        this->orderData.insert(make_pair(this->mSize, line));
        this->mSize++;
    }
}

void Order::updateOrder() {
    if(this->mSize == 0) {
        return;
    }

    ofstream ofs(ORDER_FILE, ios::trunc | ios::out);
    for(auto &it: this->orderData) {
        ofs << "stuID:" << it.second["stuID"] << " ";
        ofs << "stuName:" << it.second["stuName"]<< " ";
        ofs << "status:" << it.second["status"] << " ";
        ofs << "date:" << it.second["date"] << " ";
        ofs << "interval:" << it.second["interval"] << " ";
        ofs << "room:" << it.second["room"] << endl;
    }

    ofs.close();
}

#endif //COMPUTERROOMRESERVATION_ORDER_HPP
