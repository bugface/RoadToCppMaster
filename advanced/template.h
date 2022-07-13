//
// Created by alex on 7/11/22.
//

#ifndef ADVANCED_TEMPLATE_H
#define ADVANCED_TEMPLATE_H

//#include<bits/stdc++.h>
#include "iostream"

using namespace std;

struct ForTest {
    string field1;
    int field2;

    void show() const {
        cout << field1 << " " << field2 << endl;
    }
};

template<typename T>
void swapTemplate(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void mySort(T &arr, int len) {
    for (int i = 0; i < len; ++i) {
        int min_index = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min_index]) min_index = j;
        }

        if (i != min_index) swapTemplate(arr[min_index], arr[i]);
    }
}

template<typename T>
void printArr(T &arr) {
    for (auto *it = cbegin(arr); it < cend(arr); ++it) {
        cout << *it << " ";
    }

    cout << endl;
}

template<typename T>
bool myComparator(T &a, T &b) {
    return a == b;
}

template<> bool myComparator(ForTest &a, ForTest &b) {
    cout << "use template reload" << endl;
    if (a.field1 == b.field1 && a.field2 == b.field2){
        return true;
    }
    else {
        return false;
    }
}

void testSort() {
    char charr[] = "cbafedm";
    int intarr[] = {3, 2, 4, 1, 5};
    mySort(charr, 7);
    mySort(intarr, 5);
    printArr(charr);
    printArr(intarr);
}

#endif //ADVANCED_TEMPLATE_H