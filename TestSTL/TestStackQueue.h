//
// Created by alex on 7/21/22.
//

#ifndef TESTSTL_TESTSTACKQUEUE_H
#define TESTSTL_TESTSTACKQUEUE_H
#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class TestStackQueue {
public:
    int a;

    explicit TestStackQueue(int a) {
        this->a = a;
    }
};

void testStack() {
    stack<TestStackQueue> s;

    for (int i=0; i<10; ++i) {
        TestStackQueue tsq(i);
        s.push(tsq);
    }

    cout << s.size() << endl;

    while(! s.empty()) {
        cout << s.top().a << " ";
        s.pop();
    }
    cout << endl;
}

void pringQueue(queue<int> q) {
    while (! q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void testQueue() {
    queue<int> q;
    queue<int> q2;
    queue<int> q3;

    for (int i=0; i<10; ++i) {
        q.push(i);

        if (i % 2 == 0) {
            q2.push(i);
        } else {
            q3.push(i);
        }
    }

    cout << q.size() << " " << q.back() << " " << q.front() << endl;

    while(! q.empty()) {
        cout << q.front() <<  " "  << q.back() << endl;
        q.pop();
    }

    pringQueue(q2);
    pringQueue(q3);
    q2.swap(q3);
    pringQueue(q2);
    pringQueue(q3);

    queue<TestStackQueue> q4;
    q4.push(TestStackQueue(10));
    q4.emplace(TestStackQueue(11));
    cout << q4.front().a << " " << q4.back().a << endl;
}


#endif //TESTSTL_TESTSTACKQUEUE_H
