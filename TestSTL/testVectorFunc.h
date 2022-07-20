//
// Created by alex on 7/17/22.
//

#ifndef TESTSTL_TESTVECTORFUNC_H
#define TESTSTL_TESTVECTORFUNC_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void printVector(vector<T> const &v) {
    for (auto it = v.begin(); it < v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void testVectorConstructor() {
    vector<int> v1;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i + 1);
    }
    printVector(v1);

    vector<int> v2(v1.begin() + 1, v1.end() - 1);
    printVector(v2);

    vector<int> v3(10, 100);
    printVector(v3);

    vector<int> v4 = v1; // deep copy
    v1[0] = -1;
    printVector(v1);
    printVector(v4);

    vector<int> v5;
    v5.assign(v1.begin() + 2, v1.end() - 2);
    printVector(v5);

    cout << v1.capacity() << endl;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i + 10);
    }
    printVector(v1);
    cout << v1.capacity() << endl;

    v1.insert(v1.begin() + 1, -2);
    printVector(v1);

    cout << v1.at(1) << v1.front() << v1.back() << endl;

    v1.swap(v3);
    printVector(v1);
    printVector(v3);

    //swap usage: clear unused RAM after resize
    v1.assign(10000, 10);
    cout << v1.capacity() << v1.size() << endl;
    v1.resize(5);
    cout << v1.capacity() << v1.size() << endl;
    vector<int>(v1).swap(v1); // use v1.shrink_to_fit();
    cout << v1.capacity() << v1.size() << endl;

    // check how many time vector relocate RAM
    // how to use reserver to avoid
    int num = 0;
    int *p = nullptr;
    vector<int> vn;
    for (int i = 0; i < 10000; ++i) {
        vn.push_back(i);
        if (p != &vn[0]) {
            p = &vn[0];
            num++;
        }
    }

    cout << "no reserve: " << num << endl;

    num = 0;
    p = nullptr;
    vector<int> vm;
    vm.reserve(10001);
    for (int i = 0; i < 10000; ++i) {
        vm.push_back(i);
        if (p != &vm[0]) {
            p = &vm[0];
            num++;
        }
    }

    cout << "use reserve: " << num << endl;
}

#endif //TESTSTL_TESTVECTORFUNC_H
