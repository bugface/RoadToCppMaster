//
// Created by alex on 7/13/22.
//

#include "testvector.h"

template<class T>
void myPrint(T &val) {
    cout << val << endl;
}

void test1() {
    vector<int> v1;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i * 10);
    }

    // loop vector
    for (int &it: v1) {
        cout << it << " ";
    }
    cout << endl;

    for (auto it = v1.begin(); it != v1.end(); it++) {
        cout << *it + 1 << " ";
    }
    cout << endl;

    auto itBegin = v1.begin();
    auto itEnd = v1.end();
    while (itBegin != itEnd) {
        cout << *itBegin + 2 << " ";
        itBegin++;
    }
    cout << endl;

    for_each(v1.begin(), v1.end(), myPrint<int>);
}

void test2() {
    vector<testvector> v;

    for (int i = 1; i < 5; ++i) {
        testvector tv("tv" + to_string(i), i * 10 + 8);
        v.push_back(tv);
    }

    for (testvector &tv: v) {
        cout << tv.name << " " << tv.age << endl;
    }

    for (auto it = v.begin(); it < v.end(); it++) {
        cout << (*it).name << it->name << " " << it->age << endl;
    }
}

void test3() {
    vector<testvector *> v;
    testvector tv("tv1", 18);
    v.push_back(&tv);
    testvector tv1("tv2", 28);
    v.push_back(&tv1);
    testvector tv2("tv3", 38);
    v.push_back(&tv2);
    testvector tv3("tv4", 48);
    v.push_back(&tv3);

    for (testvector *it: v) {
        cout << it->name << " " << it->age << endl;
    }

    for (auto it = v.begin(); it < v.end(); it++) {
        cout << (*it)->name << " " << (*it)->age << endl;
    }

    auto itBegin = v.begin();
    auto itEnd = v.end();
    while (itBegin != itEnd) {
        cout << (*itBegin)->name << " ";
        itBegin++;
    }
}

void test4() {
    // nested vector
    vector<vector<int>> v;

    for (int i = 0; i < 5; ++i) {
        vector<int> vt;
        for (int j = 0; j < 5; ++j) {
            vt.push_back(i + j);
        }
        v.push_back(vt);
    }

    for (vector<int> const& vt: v) {
        for (auto it = vt.begin(); it < vt.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

}

