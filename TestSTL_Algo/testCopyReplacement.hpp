//
// Created by alex on 7/30/22.
//

#ifndef UNTITLED_TESTCOPYREPLACEMENT_HPP
#define UNTITLED_TESTCOPYREPLACEMENT_HPP
#pragma once

#include <algorithm>
#include <random>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <list>

using namespace std;

void testCopy() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i + 1);
    }

    vector<int> v2; // we need to pre alloc space
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), print02);
    cout << endl;
}

testAlgo toNeg(testAlgo& x) {
    x.a = -x.a;
    return x;
}

void testReplace() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i + 1);
        v1.push_back(i + 1);
    }

    replace(v1.begin(), v1.end(), 3, -3);
    for_each(v1.begin(), v1.end(), print02);
    cout << endl;

    replace_if(v1.begin(), v1.end(), cond1, -1);
    for_each(v1.begin(), v1.end(), print02);
    cout << endl;

    vector<testAlgo> v4;
    for (int i = 0; i < 10; ++i) {
        testAlgo ta(i, "string_" + to_string(i + 1));
        v4.push_back(ta);
    }
    for_each(v4.begin(), v4.end(), toNeg);
    for (const testAlgo &t: v4) {
        cout << t.a << " " << t.b << " ";
    }
    cout << endl;
}


#endif //UNTITLED_TESTCOPYREPLACEMENT_HPP
