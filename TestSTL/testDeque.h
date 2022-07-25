//
// Created by alex on 7/21/22.
//

#ifndef TESTSTL_TESTDEQUE_H
#define TESTSTL_TESTDEQUE_H

#include <iostream>
#include <deque>
#include <algorithm>
#include <random>

using namespace std;

template<class T>
void printDeque(const deque<T> &d) {
    for (auto it = d.begin(); it < d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void testDeque() {
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i + 1);
    }
    printDeque(d1);

    deque<int> d2(d1.begin() + 1, d1.end());
    printDeque(d2);

    deque<int> d3(10, -1);
    deque<int> d4(d3);
    d3.at(3) = -2;
    d3.assign(10, -2);
    printDeque(d3);
    printDeque(d4);

    deque<int> d5;

    cout << d1.empty() << " " << d5.empty() << endl;
    cout << d1.size() << " " << d5.size() << endl;

    d4.resize(20);
    printDeque(d4);
    d4.resize(3);
    printDeque(d4);

    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            d5.push_back(i);
        } else {
            d5.push_front(i);
        }
    }
    printDeque(d5); // 9 7 5 3 1 0 2 4 6 8
    d5.pop_back();
    d5.pop_front();
    printDeque(d5);

    // 7 5 3 1 -1 0 2 4 6
    d5.insert(d5.begin() + 4, -1);
    printDeque(d5);

    // 7 5 3 1 -1 -2 -2 0 2 4 6
    d5.insert(d5.begin() + 5, 2, -2);
    printDeque(d5);

    // 7 5 3 1 -1 2 3 4 5 6 7 8 9 10 -2 -2 0 2 4 6
    d5.insert(d5.begin() + 6, d1.begin() + 1, d1.end());
    printDeque(d5);

    int shift = (int) d1.size() - 1;
    d5.erase(d5.begin() + 6, d5.begin() + 6 + shift);
    // 7 5 3 1 -1 -2 -2 0 2 4 6
    printDeque(d5);

    d5.clear();
    cout << d5.empty() << endl;

    cout << d1.front() << " " << d1.back() << endl;

    // all these can be applied for container that support random access
    // e.g., vector
    shuffle(d1.begin(), d1.end(), mt19937(random_device()()));
    printDeque(d1);
    sort(d1.begin(), d1.end());
    printDeque(d1);
    reverse(d1.begin(), d1.end());
    printDeque(d1);
}

#endif //TESTSTL_TESTDEQUE_H
