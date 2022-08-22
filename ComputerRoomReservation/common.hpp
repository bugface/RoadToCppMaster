//
// Created by alex on 8/19/22.
//

#ifndef COMPUTERROOMRESERVATION_COMMON_HPP
#define COMPUTERROOMRESERVATION_COMMON_HPP

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void returnInfo(int n = 2) {
    string sleep = "sleep " + to_string(n);
    system(sleep.c_str());
    system("clear");
}

void sysExit() {
    cout << "Thank you for use, Bye." << endl;
    returnInfo();
}

struct MatchObj {
    int i;
    string a;
    string b;

    MatchObj(int i, string a, string b) {
        this->i = i;
        this->a = move(a);
        this->b = move(b);
    }
};

vector<MatchObj> load_login_info(const string &fn) {
    ifstream ifs;
    ifs.open(fn, ios::in);

    if (!ifs.is_open()) {
        ofstream ofs(fn, ios::trunc);
        ofs.close();
        cout << "No info found, a new file " << fn << " has been created." << endl;
    }

    vector<MatchObj> v;
    int tid;
    string tname;
    string tpwd;
    while (ifs >> tid && ifs >> tname && ifs >> tpwd) {
        v.emplace_back(tid, tname, tpwd);
    }

    return v;
}

bool login_validation(const MatchObj &p, const vector<MatchObj> &v) {
    return any_of(v.begin(), v.end(), [&p](auto &t) {
        return t.i == p.i && t.a == p.a && t.b == p.b;
    });
}

bool check_id_collision(int i, const vector<MatchObj> &v) {
    return any_of(v.begin(), v.end(), [i](auto &t) {
        return t.i == i;
    });
}

int recommend_id(const vector<MatchObj> &v) {
    vector<int> ids;
    for (auto &it: v) {
        ids.push_back(it.i);
    }

    std::sort(ids.begin(), ids.end());
    return ids.back() + 1;
}

void authFail() {
    cout << "authentication failed." << endl;
}

#endif //COMPUTERROOMRESERVATION_COMMON_HPP
