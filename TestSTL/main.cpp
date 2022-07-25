#include <iostream>
#include "testvector.h"
#include "TestString.h"
#include "testVectorFunc.h"
#include "testDeque.h"
#include "RefScore.h"
#include "TestStackQueue.h"
#include "TestListSet.h"

using namespace std;

int main() {
    test1();
    test2();
    test3();
    test4();

    testString1();
    testString2();
    testString3();
    testStringFind();
    testStringCompare();
    tsetGetCharFromString();
    testInsertDeleteString();

    testVectorConstructor();

    testDeque();
    runRefScore();

    testStack();
    testQueue();

    testList();
    testSet();

    return 0;
}
