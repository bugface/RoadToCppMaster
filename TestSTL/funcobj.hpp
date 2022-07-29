//
// Created by alex on 7/28/22.
//

#ifndef TESTSTL_FUNCOBJ_HPP
#define TESTSTL_FUNCOBJ_HPP
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// func obj return bool

bool funcbool(int a) {
    return a > 5;
}

class GreaterThan10 {
public:
    bool operator()(int a) {
        return a > 10;
    }
};

class Negate{
public:
    int operator()(int n) {
       return -n;
    }
};

class Plus {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

void testBool() {
    vector<int> v;

    for (int i=0; i<10;++i) {
        v.push_back(i);
    }

    // check if v has number > 5
    auto it = find_if(v.begin(), v.end(), funcbool);
    cout << *it << *(++it) << endl;
    it = find_if(v.begin(), v.end(), GreaterThan10());
    cout << (it == v.end()) << endl;

    cout << Negate()(50) << endl;
    cout << Plus()(30, 20) << endl;
}


#endif //TESTSTL_FUNCOBJ_HPP
