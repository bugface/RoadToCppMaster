//
// Created by Yang,Xi on 6/16/22.
//
#include <iostream>
#include "myStruct.h"
#include "function.h"

using namespace std;

void testStructParam(stu s) {
    // if change only change in this function scope
    cout << s.name << s.age << s.score << endl;
}

void testStructParam(stu * s) {
    // if change will change original value
//    s->name = "1";
    cout << s->name << s->score << s->age  << endl;
}

void testStructParamConst(const stu * s) {
    // if change will change original value
//    s->name = "1";
    cout << s->name << s->score << s->age  << endl;
}

int testFunction(int a, int b) {
    return (a + b) * 10 ;
}

void testPointer() {
    int a = 10;
    int * p; // define a int type pointer
    p = &a; // p piont to a's address
    *p = 1000; // we change the value at the address so all reference to this address will change
    int b = *p;  // * pointer is way to get the value at the pointer address (decode pointer)
    cout << p << " " << a << " " << b << endl;  // a = b = 1000
    cout << sizeof (int *) << endl; // 8 bytes under x86_64 for int pointer

    int *pp = nullptr; // cannot visit => illigeal for *pp
    cout << pp << endl;
    // do not visit nullptr or wild pointer

    const int * p1;
    p1 = &a;  // const pointer => pointer can point to different address but cannot modify value
    p1 = &b;  // valid
    // *p1 = 1000;  not valid

    int * const p2 = &a;  // cannot point to diff address but can change value
    // p2 = &b;  invalid
    *p2 = 21;

    const int * const p3 = &a; // p3 cannot point to diff address and cannot modify value

    // point array
    int arr[] = {1,2,3,4,5};
    int * pa  = arr;
    cout << *pa << endl;
    pa++;  // point move to next address (+8 byte)
    cout << *pa << endl;

    int * p4 = arr;
    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++) {
        cout << i << " " << *p4 << " ";
        p4++;
    }
    cout << endl;
}

// address passin
void testPointerFunction(int * p1, int * p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubbleSort(int * arr, int len) {
    for (int i=0; i<(len-1); ++i) {
        for (int j=0; j<(len - i - 1); ++j) {
            if (arr[j] > arr[j+1]) {
                testPointerFunction(&arr[j], &arr[j+1]);
            }
        }
    }
}


