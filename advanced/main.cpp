#include <iostream>
#include "template.h"
#include "TemplateClass.h"
#include "TemplateInherent.h"
//#include "splitfile.cpp"
// for class template we implement both source and head in .hpp file
#include "hpp.hpp"
#include "FriendTemplate.h"
#include "CommonArray.h"

using namespace std;

int main() {
    int a = 0;
    int b = 1;
    cout << a << " " << b << endl;
    swapTemplate<int>(a, b); // explicit assign type
    cout << a << " " << b << endl;

    string s1 = "s1";
    string s2 = "s2";
    cout << s1 << " " << s2 << endl;
    swapTemplate(s1, s2); // auto inference type
    cout << s1 << " " << s2 << endl;

    auto *ft1 = new ForTest{"ft1", 1};
    auto *ft2 = new ForTest{"ft2", 2};
    ft1->show();
    ft2->show();
    swapTemplate<ForTest *>(ft1, ft2); // recommend to tell what type I need
    ft1->show();
    ft2->show();

    testSort();

    cout << myComparator(a, b) << endl;
    int c = 0;
    cout << myComparator(b, c) << endl;

    cout << "***" << endl;
    auto *ft7 = new ForTest{"ft2", 2};
    cout << myComparator(ft1, ft7) << endl;
    cout << myComparator(*ft1, *ft7) << endl;
    cout << "***" << endl;

    ForTest ft3 = {"a", 3};
    ForTest ft4 = {"a", 3};
    ForTest ft5 = {"b", 2};
    cout << myComparator(ft3, ft4) << endl;
    cout << myComparator(ft3, ft5) << endl;

    testTemplageClass();

    TemplateClass<string, int> tc1 = {"test1", 2};
    printTemplateClass1(tc1);
    printTemplateClass2(tc1);
    printTemplateClass3(tc1);

    test1();

    splitfile<string> sp("test");
    sp.show();

    testFriendTemplate();

    testCommonArr();

    testCommonArr1();

    testCommonArr2();

//    int arr[] = {1,2,4,5,6};
//
//    for(auto i : arr) cout << i << " ";
//    cout << endl;
//
//    int *arr1 = new int[5];
//    for (int i=0; i<5; ++i) arr1[i] = i + 10;
//    for (int i=0; i<5; ++i) cout << arr1[i] << " ";
//    delete[] arr1;
//    cout << endl;

    return 0;
}
