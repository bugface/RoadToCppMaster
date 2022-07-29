//
// Created by alex on 7/26/22.
//

#ifndef TESTSTL_STAFFGROUPING_HPP
#define TESTSTL_STAFFGROUPING_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

#define Marketing 0
#define Engineering 1
#define HR 2

using namespace std;

class StaffGrouping {
public:
    string name;
    int dept_id;

    StaffGrouping(const string &name, int dept_id) {
        this->name = name;
        this->dept_id = dept_id;
    }
};

bool cmpp(int idx1, int idx2) {
    return idx1 > idx2;
}

void groupStaff() {
    vector<StaffGrouping> staff;
    for (int i = 0; i < 10; ++i) {
        StaffGrouping p(("staff_" + to_string(i)), i % 3);
        staff.emplace_back(p);
    }

    multimap<int, vector<StaffGrouping>, decltype(cmpp) &> m(cmpp);
    for (const auto &it: staff) {
        cout << "name: " << it.name << " dept id:" << it.dept_id << endl;
        if (m.count(it.dept_id) == 0) {
            vector<StaffGrouping> v;
            v.emplace_back(it);
            m.insert(make_pair(it.dept_id, v));
        } else {
            m.find(it.dept_id)->second.emplace_back(it);
        }
    }

    for (const auto &it: m) {
        cout << "dept: " << it.first << endl;
        for (const auto &s: it.second) {
            cout << s.name << " ";
        }
        cout << endl;
    }
}

void groupStaff1() {
    vector<StaffGrouping> staff;
    for (int i = 0; i < 10; ++i) {
        StaffGrouping p(("staff_" + to_string(i)), i % 3);
        staff.emplace_back(p);
    }

    multimap<int, StaffGrouping, decltype(cmpp) &> m(cmpp);
    for (const auto &it: staff) {
        cout << "name: " << it.name << " dept id:" << it.dept_id << endl;
        m.insert(make_pair(it.dept_id, it));
    }

    auto pos = m.find(Engineering);
    for (int i = 0; i < m.count(Engineering); ++pos, ++i) {
        cout << pos->second.name << " ";
    }
    cout << endl;

    pos = m.find(HR);
    for (int i = 0; i < m.count(HR); ++pos, ++i) {
        cout << pos->second.name << " ";
    }
    cout << endl;

    pos = m.find(Marketing);
    for (int i = 0; i < m.count(Marketing); ++pos, ++i) {
        cout << pos->second.name << " ";
    }
    cout << endl;
}


#endif //TESTSTL_STAFFGROUPING_HPP
