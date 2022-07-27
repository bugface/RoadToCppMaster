#include <iostream>
#include "testvector.h"
#include "TestString.h"
#include "testVectorFunc.h"
#include "testDeque.h"
#include "RefScore.h"
#include "TestStackQueue.h"
#include "TestListSet.h"
#include "TestMap.h"
#include <boost/smart_ptr/shared_ptr.hpp>

using namespace std;

class A{};

int main() {
    boost::shared_ptr<A> pA(new A);
    cout << pA.get() << endl;
    boost::shared_ptr<A> pB(pA);
    cout << pA.get() << endl;
    cout << pB.get() << endl;

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
    testSetSort();

    testMap();
    testSortMap();

    return 0;
}
