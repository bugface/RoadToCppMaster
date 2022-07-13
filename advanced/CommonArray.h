//
// Created by alex on 7/12/22.
//

#ifndef ADVANCED_COMMONARRAY_H
#define ADVANCED_COMMONARRAY_H

#include <iostream>
#include <string>
#include <utility>

using namespace std;

/*
 *  1. save all types of data
 *  2. data in heap
 *  3. array capacity in constructor
 *  4. provide copy constructor and override operator= to avoid shallow copy
 *  5.provide insertTail and deleteTail methods
 *  6.use i to visit element
 *  7.getEleNum, get capacity
 */

template<typename T>
class CommonArray {
private:
    int eleNum;
    int capacity;

public:
    T *p;

    CommonArray(int capacity) {
//        cout << "constructor with parameter" << endl;
        this->capacity = capacity;
        this->eleNum = 0;
        p = new T[capacity];
    }

    ~CommonArray() {
//        cout << "de-constructor" << endl;
        delete[] this->p;
        this->p = nullptr;
    }

    // copy constructor
    CommonArray(const CommonArray &other) {
//        cout << "constructor with copy" << endl;
        cout << "" << endl;
        this->capacity = other.capacity;
        this->eleNum = other.eleNum;
        this->p = new T[this->capacity];
        for (int i = 0; i < this->eleNum; ++i) {
            this->p[i] = other.p[i];
        }
    }

    // operator=
    CommonArray &operator=(const CommonArray &other) {
        if (this->p != nullptr) {
            delete[] this->p;
            this->p = nullptr;
        }

        this->capacity = other.capacity;
        this->eleNum = other.eleNum;
        this->p = new T[this->capacity];
        for (int i = 0; i < this->eleNum; ++i) {
            this->p[i] = other.p[i];
        }

        return *this;
    }

    int getCapacity() {
        return this->capacity;
    }

    int getElementNum() {
        return this->eleNum;
    }

    // insert in tail
    void push_back(const T &t) {
        if (this->eleNum == this->capacity) return;

        this->p[this->eleNum] = t;
        this->eleNum++;
    }

    // delete at tail
    T pop_back() {
        if (this->eleNum == 0) return -1;
        T temp = this->p[this->eleNum - 1];
        this->eleNum--;
        return temp;
    }

    //visit via index (and can be on left val)
    T &operator[](int index) {
        return this->p[index];
    }
};

void testCommonArr() {
    CommonArray<int> arr(5);
    CommonArray<int> arr1(arr);
    CommonArray<int> arr2(10);
    cout << arr.getElementNum() << endl;
    arr2 = arr;
    cout << arr2.getCapacity() << endl;
}

void printIntArr(CommonArray<int> &arr) {
    for (int i = 0; i < arr.getElementNum(); ++i) {
        cout << arr[i] << " ";
//        cout << arr.pop_back() << " ";
    }

    cout << endl;
}

void testCommonArr1() {
    CommonArray<int> arr(5);
    cout << arr.getElementNum() << arr.getCapacity() << endl;
    for (int i = 0; i < 5; ++i) {
        arr.push_back(i);
        cout << arr.p[i] << endl;
    }
    printIntArr(arr);

    while (arr.getElementNum() > 0) {
        cout << arr.getElementNum() << arr.pop_back() << " ";
    }
    cout << endl;

    CommonArray<int> arr1(10);
    for (int i = 0; i < 10; ++i) {
        arr1.push_back(i);
    }

    arr = arr1;
    printIntArr(arr);
    arr.pop_back();
    printIntArr(arr);
    cout << arr.getElementNum() << " " << arr.getCapacity() << endl;
    printIntArr(arr1);
    cout << arr1.getElementNum() << " " << arr1.getCapacity() << endl;
}

class TestElement {
public:
    string s;
    int a;

    TestElement() = default;

    TestElement(string s, int a) {
        this->s = move(s);
        this->a = a;
    }
};

void printTeArr(CommonArray<TestElement> &arr) {
    for (int i = 0; i < arr.getElementNum(); ++i) {
        cout << arr[i].s << " " << arr[i].a << endl;
    }
}

void testCommonArr2() {
    CommonArray<TestElement> arr(5);

    for (int i = 0; i < 5; ++i) {
        TestElement te("test" + to_string(i), i);
        arr.push_back(te);
    }

    printTeArr(arr);

    CommonArray<TestElement> arr1(arr);
    printTeArr(arr1);
}


#endif //ADVANCED_COMMONARRAY_H
