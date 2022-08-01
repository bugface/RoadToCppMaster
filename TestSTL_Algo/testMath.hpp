//
// Created by alex on 7/31/22.
//

#ifndef UNTITLED_TESTMATH_HPP
#define UNTITLED_TESTMATH_HPP
#pragma once

#include <algorithm>
#include <random>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <numeric>

using namespace std;

class testMath {

};

int op(int x, int y) {
    if (x % 2 == 0) {
        return x + y;
    } else {
        return y - x;
    }
}

void testMath() {
    vector<int> v1;

    for (int i = 1; i < 101; ++i) {
        v1.push_back(i);
    }

    int total = accumulate(v1.begin(), v1.end(), 0);
    cout << total << endl;

    total = accumulate(v1.begin(), v1.end(), 0, op);
    cout << total << endl;

    vector<int> v2;
    v2.resize(10);
    for_each(v2.begin(), v2.end(), print02);
    cout << endl;
    fill(v2.begin(), v2.end(), 1);
    for_each(v2.begin(), v2.end(), print02);
    cout << endl;
}

void testSetRelated() {
    set<int> s1;
    set<int> s2;
    s1.insert(1);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(2);

    s2.insert(3);
    s2.insert(1);
    s2.insert(5);
    s2.insert(4);
    s2.insert(7);

    set<int> s3;
    set_union(s1.begin(), s1.end(),
              s2.begin(), s2.end(),
              inserter(s3, s3.begin()));

    for (auto const &e: s3) {
        cout << e << ' ';
    }
    cout << endl;

    set<int> s4;
    set_intersection(s1.begin(), s1.end(),
                     s2.begin(), s2.end(),
                     inserter(s4, s4.begin()));
    for (auto const &e: s4) {
        cout << e << ' ';
    }
    cout << endl;

    set<int> s5;
    set_difference(s1.begin(), s1.end(),
                     s2.begin(), s2.end(),
                     inserter(s5, s5.begin()));
    set_difference(s2.begin(), s2.end(),
                   s1.begin(), s1.end(),
                   inserter(s5, s5.begin()));
    for (auto const &e: s5) {
        cout << e << ' ';
    }
    cout << endl;

    // apply set operation on vector
    // vector need preallocate space
    vector<int> v1;
    vector<int> v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(2);

    v2.push_back(3);
    v2.push_back(1);
    v2.push_back(5);
    v2.push_back(4);
    v2.push_back(7);

    // set operation must require sorted data
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> v3;
    v3.resize(min(v1.size(), v2.size()));
    auto v3_end = set_intersection(v1.begin(), v1.end(),
                     v2.begin(), v2.end(),
                     v3.begin());
    for_each(v3.begin(), v3_end, print02);
    cout << endl;

    v3.resize(v1.size() + v2.size());
    v3_end = set_union(v1.begin(), v1.end(),
                       v2.begin(), v2.end(),
                       v3.begin());
    for_each(v3.begin(), v3_end, print02);
    cout << endl;
}


#endif //UNTITLED_TESTMATH_HPP
