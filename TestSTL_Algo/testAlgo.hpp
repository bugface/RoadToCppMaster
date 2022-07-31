//
// Created by alex on 7/30/22.
//

#ifndef UNTITLED_TESTALGO_HPP
#define UNTITLED_TESTALGO_HPP

#pragma once

#include <algorithm>
#include <random>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <list>

using namespace std;

class testAlgo {
public:
    int a;
    string b;

    explicit testAlgo(int a, const string &b) {
        this->a = a;
        this->b = b;
    }

    testAlgo() = default;

    bool operator==(const testAlgo &other) const {
        if (this->a == other.a && this->b == other.b) {
            return true;
        }
        return false;
    }
};

void print01(const vector<int> &v) {
    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;
}

void print02(int val) {
    cout << val << " ";
}

void testAlgo1() {
    // loop
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i + 1);
    }

    print01(v1);
    for_each(v1.begin() + 1, v1.end() - 1, print02);
    cout << endl;
}

int transFunc(int a) {
    return a + 10;
}

void testTransform() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i + 1);
    }

    vector<int> v2; // we need to pre alloc space
    v2.resize(v1.size());

    transform(v1.begin(), v1.end(), v2.begin(), transFunc);
    print01(v2);
}

bool cmp(const testAlgo &t1, const testAlgo &t2) {
    if (t1.a == t2.a) {
        return t1.b > t2.b;
    } else {
        return t1.a > t2.a;
    }
}

bool cmp2(const testAlgo &t1, const testAlgo &t2) {
    if (t1.a == t2.a) {
        return t1.b < t2.b;
    } else {
        return t1.a < t2.a;
    }
}

bool cmp1(const testAlgo &t1, const testAlgo &t2) {
    return t1.a == t2.a && t1.b == t2.b;
}

bool cond1(int x) {
    return x > 5;
}

bool cond2(const testAlgo &item) {
    return item.a < 6;
}

void testSearch() {
    list<int> l;
    l.push_back(2);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(7);
    l.push_back(8);
    l.push_back(8);
    l.push_back(8);
    l.push_back(1);
    l.push_back(3);

    auto it = find(l.begin(), l.end(), 7);
    cout << (it == l.end()) << " " << *it << endl;
    it = find(l.begin(), l.end(), -1);
    cout << (it == l.end()) << " " << *it << endl;

    set<testAlgo, decltype(cmp2) *> s(cmp2);
    for (int i = 0; i < 10; ++i) {
        testAlgo ta(i, "string_" + to_string(i + 1));
        s.insert(ta);
    }

    for (const testAlgo &x: s) {
        cout << x.a << " " << x.b << endl;
    }

    testAlgo ta1(3, "string_4");
    // we should use this (co`ntainer method)
    auto it1 = s.find(ta1);
    cout << (it1 == s.end()) << " " << it1->a << " " << it1->b << endl;
    testAlgo ta2(3, "string_3");
    it1 = s.find(ta2);
    cout << (it1 == s.end()) << endl;
    // to use find here, we need to redefine == in class
    auto it2 = find(s.begin(), s.end(), ta1);
    cout << (it2 == s.end()) << " " << it2->a << " " << it2->b << endl;

    auto it3 = find_if(l.begin(), l.end(), cond1);
    cout << (it3 == l.end()) << " " << *it3 << endl;
    for (; it3 != l.end(); ++it3) {
        cout << *it3 << " ";
    }
    cout << endl;

    it1 = find_if(s.begin(), s.end(), cond2);
    cout << (it1 == s.end()) << " " << it1->a << " " << it1->b << endl;

    // find adjacent same element
    auto it5 = adjacent_find(l.begin(), l.end());
    cout << (it5 == l.end()) << " " << *it5 << endl;

    // bisect - need to sort first
    bool flag = binary_search(s.begin(), s.end(), ta1, cmp1);
    cout << flag << endl;
    flag = binary_search(s.begin(), s.end(), ta2, cmp1);
    cout << flag << endl;

    //count
    cout << s.count(ta1) << endl;
    cout << count_if(s.begin(), s.end(), cond2) << endl;

    cout << is_sorted(s.begin(), s.end(), cmp) << endl;

    vector<testAlgo> v1;
    for (int i = 0; i < 10; ++i) {
        testAlgo ta(i, "string_" + to_string(i + 1));
        v1.push_back(ta);
    }

    vector<testAlgo> v2;
    for (int i = 5; i < 15; ++i) {
        testAlgo ta(i, "string_" + to_string(i + 1));
        v2.push_back(ta);
    }

    vector<testAlgo> v3;
    unsigned long finalSize = v1.size() + v2.size();
    v3.resize(finalSize);

    //random shuffle
    shuffle(v1.begin(), v1.end(), mt19937(random_device()()));
    for (const testAlgo &t: v1) {
        cout << t.a << " " << t.b << " ";
    }
    cout << endl;

    // note set/map not support sort since it has their own sort defined
    sort(v1.begin(), v1.end(), cmp);
    for (const testAlgo &t: v1) {
        cout << t.a << " " << t.b << " ";
    }
    cout << endl;

    // v1 v2 must be in same order
    sort(v2.begin(), v2.end(), cmp);
    merge(v1.begin(), v1.end(),
          v2.begin(), v2.end(),
          v3.begin(), cmp);
    for (const testAlgo &t: v3) {
        cout << t.a << " " << t.b << " ";
    }
    cout << endl;

    reverse(v3.begin(), v3.end());
    for (const testAlgo &t: v3) {
        cout << t.a << " " << t.b << " ";
    }
    cout << endl;
}

#endif //UNTITLED_TESTALGO_HPP