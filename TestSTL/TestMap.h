//
// Created by alex on 7/25/22.
//

#ifndef TESTSTL_TESTMAP_H
#define TESTSTL_TESTMAP_H
#include <map>
#include <iostream>
#include <string>

using namespace std;

class TestMap {
public:
    int a;
    string b;
};

void printIntMap(map<int, int> &m) {
    for(auto & it : m) {
        cout << "(" << it.first << " " << it.second << ") ";
    }

    cout << endl;
}

void testMap() {
    map<int, int> m;
    // map use red-black tree so the key will be ordered ascending
    for (int i = 0; i < 10; ++i) {
        m.insert(pair<int, int>(i, i%3));
//        m.insert(pair<int, int>(i, i));
    }
    printIntMap(m);

    map<int, int> m1;
    // map use red-black tree so the key will be ordered ascending
    for (int i = 0; i < 10; ++i) {
        m1.insert(pair<int, int>(i, i));
    }

    cout << m1.size() << " " << m1.empty() << endl;

    m.swap(m1);
    printIntMap(m);
    printIntMap(m1);

    m.insert(pair<int, int>(-1, -2));
    m.insert(pair<int, int>(100, -3));
    m.insert(make_pair(11, 1)); // best
    m.insert(map<int, int>::value_type(12, 2));
    m[13] = 3; // used for key to get value
    printIntMap(m);

    cout << m[8] << endl;

    m.erase(4); // delete by key
    printIntMap(m);
    m1.clear();
    cout << m1.size() << " " << m1.empty() << endl;

    auto idx = m.find(3);
    cout << (idx == m.end()) << " " << idx->first << " " << idx->second << endl;
    idx = m.find(4);
    cout << (idx == m.end()) << endl;

    cout << m.count(3) << endl;
    cout << m.count(4) << endl;

    multimap<int, int> mm;
    for (int i = 0; i < 10; ++i) {
        mm.insert(pair<int, int>(1, i));
    }
    for(auto &e: mm) {
        cout << e.first << " " << e.second << endl;
    }
    cout << mm.count(1) << endl;
    cout << m.find(1)->second << endl;
}

bool comp(int v1, int v2) {
    return v1 > v2;
}

void testSortMap() {
    map<int, int> m;
    m.insert(make_pair(3, 5));
    m.insert(make_pair(1, 5));
    m.insert(make_pair(5, 5));
    m.insert(make_pair(2, 5));
    m.insert(make_pair(4, 5));
    printIntMap(m);

    map<int, int, decltype(comp)&> m1(comp);
    m1.insert(make_pair(3, 5));
    m1.insert(make_pair(1, 5));
    m1.insert(make_pair(5, 5));
    m1.insert(make_pair(2, 5));
    m1.insert(make_pair(4, 5));
    for (auto it: m1) {
        cout << "(" << it.first << " " << it.second << ") ";
    }

    cout  << endl;
}


#endif //TESTSTL_TESTMAP_H
