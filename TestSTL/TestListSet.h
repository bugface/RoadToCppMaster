//
// Created by alex on 7/24/22.
//

#ifndef TESTSTL_TESTLISTSET_H
#define TESTSTL_TESTLISTSET_H

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class TestListSet {
public:
    int a;

    explicit TestListSet(int a) {
        cout << "call constructor" << endl;
        this->a = a;
    }

    ~TestListSet() {
        cout << "call deconstructor" << endl;
    }
};

struct PP {
    int a;
    int b;
    string s;
};

template<class T>
void printList(const list <T> &l) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;
}

bool isOdd(int i) {
    return (i % 2) == 0;
}

bool myCompare(int x, int y) {
    return x > y;
}

bool comparePP(PP &p1, PP &p2) {
    if (p1.a == p2.a) {
        if (p1.b == p2.b) {
            return p1.s > p2.s;
        } else {
            return p1.b > p2.b;
        }
    }else {
        return p1.a > p2.a;
    }
}

void testList() {
    list<int> l1;
    for (int i = 0; i < 10; ++i) {
        l1.push_back(i + 1);
    }
    printList(l1);
    for (int i = 0; i < 10; ++i) {
        l1.push_front(i + 1);
    }
    printList(l1);
    list<int> l2(l1.begin(), l1.end());
    list<int> l3(l2);
    printList(l2);
    printList(l3);
    list<int> l4(5, -1);
    printList(l4);

    l1.swap(l4);
    printList(l1);
    printList(l4);

    cout << l4.size() << endl;

    while (!l4.empty()) {
        cout << l4.front() << " " << l4.back() << endl;  // return *
        l4.pop_front();
        l4.pop_back();
    }

    l1.resize(10);
    printList(l1);  // -1 -1 -1 -1 -1 0 0 0 0 0
    l1.resize(15, -2);
    printList(l1);  // -1 -1 -1 -1 -1 0 0 0 0 0 -2 -2 -2 -2 -2
    l2.resize(5);
    printList(l2);  // 10 9 8 7 6

    // we need to first move the iter pointer to pos 2
    // then insert
    int i = 0;
    auto it = l2.begin();
    while (i < 2) {
        ++it;
        ++i;
    }
    l2.insert(it, 5);
    printList(l2);

    it = l2.begin();
    i = 0;
    while (i < 3) {
        ++it;
        ++i;
    }
    l2.erase(it);
    printList(l2);

    l1.remove(0); // delete all element = 0
    printList(l1);

    l1.clear();
    cout << l1.size() << " " << l1.empty() << endl;

    l3.remove_if(isOdd);
    printList(l3);

    list < TestListSet * > ll;
    auto *tls1 = new TestListSet(10);
    auto *tls2 = new TestListSet(20);
    ll.push_back(tls1);
    ll.push_back(tls2);
    cout << ll.front() << " " << tls1 << endl;
    ll.pop_back();
    delete tls1;
    delete tls2;

    l3.sort(myCompare); // use compare function to do descending sort
    printList(l3);

    l2.sort();
    printList(l2);
    l2.reverse();
    printList(l2);

    PP p1 = {35, 175, "abs"};
    PP p2 = {45, 180, "xsf"};
    PP p3 = {40, 170, "gdv"};
    PP p4 = {25, 190, "vsbd"};
    PP p5 = {35, 175, "pdif"};
    PP p6 = {35, 200, "xdif"};

    list <PP> lp;
    lp.push_back(p1);
    lp.push_back(p2);
    lp.push_back(p3);
    lp.push_back(p4);
    lp.push_back(p5);
    lp.push_back(p6);
    for (auto &it1: lp) {
        cout << it1.a << " " << it1.b << " " << it1.s << endl;
    }
    cout << "***************************************" << endl;
    lp.sort(comparePP);
    for (auto &it1: lp) {
        cout << it1.a << " " << it1.b << " " << it1.s << endl;
    }
}

void testSet() {

}


#endif //TESTSTL_TESTLISTSET_H
