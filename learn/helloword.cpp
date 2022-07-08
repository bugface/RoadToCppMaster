#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <numeric>
#include "function.h"
#include "myStruct.h"
#include "Circle.h"
#include "Student.h"
#include "Pointer.h"
#include "People.h"
#include "Person.h"
#include "Phone.h"
#include "Building.h"
#include "A.h"
#include "base.h"
#include "ploymorphers.h"
#include "Calc.h"
#include "computer.h"
#include "testio.h"

using namespace std;

#define DAY 7

int g_a = 10;

int myMax(int a, int b);

void test1();

//do not return local variable address
//e.g.
int * return_local_addr() {
    int a = 20;
    return &a;
}

// create variable in heap
// use new keywords
int * return_local_heap() {
    int * a = new int (10);
    return a;
}

int & funcAsLeftVal();

struct student {
    string name;
    int age;
    int score;
} s0;

void mySwap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    cout << "Hello World" << endl;

    const long a = 10;  //a is constant cannot be modified
    cout << "a = " << a << endl;
    cout << sizeof(a) << endl;
    cout << &a << endl;

    cout << "week days: " << DAY << endl;

    float b = 3.1415926f;
    double c = 3.1415926;
    cout << sizeof(b)  << " " << sizeof(c) << endl;
    float d = 3e3f;
    cout << "d = " << d << endl;

    const char ch = 'a';
    cout << sizeof(ch)  << " " << ch << endl; // ascii
    cout << 'd' - 'a' << endl;
    cout << (int)'a' << endl;

    //c style
    char str1[] = "hello world";
    cout << str1 << endl;
    //c++ style may need to include <string>
    string str2 = "hello world";
    cout << str2 << endl;

    bool flag = true;
    cout << flag << endl;
    flag = 1 == 0;
    cout << flag << endl;

//    int x = 0;
//    cin >> x;
//    cout << x << endl;

    int x = 11;
    int y = 3;
    cout << x / y << endl;
    cout << x * 1.0 / y  << endl;

    int aa = 10;
    int bb = aa++;
    cout << bb << aa << endl;
    int cc = ++aa;
    cout << cc << aa << endl;

    cout << !true << (true || false) << (true && false) << endl;

    // flow
    // if
    int score = 450;
//    cin >> score;
    if (score >= 600) {
        cout << "1" << endl;
    } else if (score >= 500 && score < 600) {
        cout << "2" << endl;
    } else {
        cout << "3" << endl;
    }

    bool dd = false;
    dd = aa < bb ? 1 : 0;
    cout << dd <<endl;

    switch (score) {
        case 600:
            cout << 1 << endl;
            break;
        case 500:
            cout << 2 << endl;
            break;
        default:
            cout << 3 << endl;
            break;
    }

    int num = 0;
    while (num < 10) {
//        cout << num++ << endl;  // 0 - 9
        cout << ++num << endl;  // 1 - 10
    }

    // set random seed
//    srand((unsigned int) time(nullptr));
    int cnt = 0;
    while (cnt < 100) {
        cout << random() % 100 + 1 << endl;
        cnt++;
    }

    int base = 100;
    do{
        int h = base / 100;
        int t = (base % 100) / 10;
        int s = (base % 10);

        if (pow(h, 3) + pow(t, 3) + pow(s, 3) == base) {
            cout << base << endl;
        }

        base ++;
    } while (base < 1000);

    for (int i = 0; i < 10; i++) {
        cout << i << endl;
    }

    for (int i = 1; i < 100; i++) {
        if (i % 10 == 7 || i / 10 == 7 || i % 7 == 0) {
            cout << "knok" << endl;
        } else {
            cout << i << endl;
        }
    }

    for (int i = 1;  i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << "*" << j << "=" << i*j << "\t";
        }
        cout << endl;
    }

    // array
    int arr[5];
    for (int i=0; i<5; i++) {
        arr[i] = i;
    };

    for (int i : arr) {
        cout << i << endl;
    };

//    int arr1[5] = {1,2,3,4,5};
    int arr1[] = {6,3,4,7,1, 2};
    for (int i : arr1) {
        cout << i << endl;
    };

    cout << sizeof(arr1) << endl;
    cout << arr1 << &arr1 << &arr1[0] << &arr1[1] << endl;
    cout << uintptr_t (&arr1[0]) << uintptr_t (&arr1[1])  << endl;

    // get max
    cout << *(&arr1 + 1) - arr1 << endl; // get arr len
    cout << *max_element(cbegin(arr1), cend(arr1)) << endl;

    // reverse
    int len = cend(arr1) - cbegin(arr1);
    for (int i=0; i<len/2; i++){
        int temp = arr1[i];
        arr1[i] = arr1[len - i - 1];
        arr1[len - i - 1] = temp;
    };
    for (int i : arr1) {
        cout << i << endl;
    };

    for (auto it=cbegin(arr1); it!= cend(arr1); ++it){
        cout << ' ' << *it;
    }
    cout << endl;

    int arr2[] = {3,5,1,8,7,9,2,6,4};
    int len1 = cend(arr2) - cbegin(arr2);
    for (int i=0; i<len1; i++) {
        for (int j = 0; j < len1 - i; j++) {
            if (arr2[j] > arr2[j + 1]) {
//                swap(arr2[j], arr2[j + 1]);
                mySwap(arr2[j], arr2[j + 1]);
            }
        }
    }

    for (auto it= cbegin(arr2); it!= cend(arr2); ++it) {
        cout << ' ' <<  *it ;
    }
    cout << endl;

    int arr3[2][3] = {
            1, 2, 3, 4, 5, 6
    };

    for (auto it1= cbegin(arr3); it1!= cend(arr3); ++it1) {
        for (auto it2=cbegin(*it1); it2!=cend(*it1); ++it2) {
            cout << *it2 << " ";
            cout << it2 << " ";
        }
        cout << endl;
    }

    int sum = 0;
    sum = accumulate(arr3[1], arr3[1] + (cend(arr3[1]) - cbegin(arr3[1])), sum);
    cout << sum << endl;

    int res = testFunction(aa, bb);
    cout << aa << " " << bb << " " << res << endl;

    int res1 = myMax(aa, bb);
    cout << aa << " " << bb << " " << res1 << endl;

    testPointer();

    testPointerFunction(&aa, &bb);
    cout << aa << " " << bb  << endl;

    int arr4[] = {3,5,1,8,7,9,2,6,4};
    bubbleSort(arr4, sizeof(arr4) / sizeof(arr4[0]));
    for (auto it= cbegin(arr4); it!= cend(arr4); ++it) {
        cout << ' ' <<  *it ;
    }
    cout << endl;

    int * test = arr4;
    cout << test << " " <<  test[3] << " " << ++test << endl;

    //use struct
    student s1;
    s1.name = "alex";
    s1.age = 18;
    s1.score = 100;

    struct student s2 = {"john", 19, 90};

    cout << s2.name << s1.age << s0.score << endl;

    MyStruct ms;
    ms.score = 66;
    ms.show();

    // struct array
    student stuArr[3] = {
            {"alex", 18, 99},
            {"john", 19, 88}
    };
    stuArr[2] = {"neo", 20, 77};
    student * p5 = &stuArr[1];
    p5->score = 87;

    for (auto it= cbegin(stuArr); it!=cend(stuArr); ++it) {
        cout << it->name << " " << it->score << endl;
    }

    //struct pointer
    student s3 = {"test", 1, 2};
    student * p6 = & s3;
    cout << p6->age << p6->name << p6->score << endl;

    stu s = {"alex", 18, 100};
    nestStruct ns;
    ns.name = "gu ailing";
    ns.id = 0;
    ns.s = s;
    ns.show();

    testStructParam(s);
    testStructParam(&s);
    testStructParamConst(&s);

    Teacher tarr[3];
    int ll = cend(tarr) - cbegin(tarr);

    srandom((unsigned int) time(nullptr));
    addTSInfo(tarr, ll);
    printInfo(tarr, ll);

    stu arr8[3];
    arr8[0] = {"jop", 20};
    arr8[1] = s;
    for (auto it= cbegin(arr8); it!=cend(arr8); ++it) {
        cout << it->name << " " << it->score << endl;
    }

    const int c_a = 10;
    static int s_a = 10;
    cout << (long) &g_a << " " << (long) &s_a <<  " " << (long) &"test" << " " << (long) &bb << " " << (long) &c_a << endl;

    int * p = return_local_addr();
    cout << * p <<endl;
    cout << * p <<endl; // something not 10 because the a value is released from stack

    int * p1 = return_local_heap();
    cout << * p1 <<endl;
    cout << * p1 <<endl;
    delete p1;
//    cout << * p1 <<endl;

    // create array in heap
    int * arr9 = new int[5];
    for (int i=0; i<5; ++i) {
        arr9[i] = 100 + i;
    }
    delete [] arr9; // release array

    // ref
    int aaa = 10;
    int ccc = 20;
    int &bbb = aaa; // bbb is reference for aaa; after initialization reference cannot change
    cout << &bbb << " " << &aaa << endl;

    mySwap(aaa, ccc);
    cout << aaa << " " << ccc << endl;

    int & ref = funcAsLeftVal();
    cout << ref << endl; // 10
    funcAsLeftVal() = 1000;  // function as left value so we can assign new value to variable
    cout << ref << endl; // 1000

    /*
     * int& ref = a;  <==>   int* const ref = &a;
     * ref = 20; <==>  *ref = 20;
     * reference is a pointer const (type * p)
     */

    //class
    auto * circle = new Circle;
    circle->r = 2.0;
    cout << circle->getCircumference() << endl;
    delete circle;
//    cout << circle->getCircumference() << endl;

    auto * s8 = new Student;
    s8->setName("alex");
    s8->setId(001);
    s8->showInfo();
    cout << endl;
    delete s8;

    // default permission for struct is public; for class is private
    Round rd;
    rd.setR(1.0);
    rd.setC(0.0, 0.0);

    Pointer pt1 (1.5, 1.5);
    cout << rd.checkPointInRound(pt1) << endl;
    cout << & pt1 << endl;

    Pointer * pt2 = new Pointer;
    pt2->setCoordinate(0.5, 0.5);
    cout << rd.checkPointInRound(* pt2) << endl;
    cout << & pt2 << endl;
    delete pt2;
    cout << "call delete 2" << endl;

    Pointer * pt3 = new Pointer;
    pt3->setCoordinate(1.0, 0.0);
    cout << rd.checkPointInRound(* pt3) << endl;
    cout << & pt3 << endl;
    delete pt3;
    cout << "call delete 3" << endl;

    // default call generator
    People pp;
    // parathesis way
    People pp1("alex", 18);
    //call with copy generator
    People pp2(pp1);
    pp1.show();
    pp2.show();

    //clear call generator
    People pp3 = People("alex", 18);
    pp3.show();
    People pp4 = People(pp1);
    pp4.show();

    //implicit
    People pp5 = 19;  // ==> People pp3 = People(18);
    People pp6 = pp5;
    pp5.show();

    test1();

//    Person ps1;
//    cout << ps1.name << " " << * ps1.age << endl;
//
//    Person ps2("joe", 22);
//    cout << ps2.name << " " << * ps2.age << endl;

    //object as class field
    Phone ph("apple", "promax", 2);
    cout << ph.brand << " " << ph.chip.brand << " " << ph.chip.gen << endl;

    CSum c1, c2;
    c1.base = 1;
    c2.base = 10;
    c2.csum(c1).csum(c1).csum(c1);
    cout << c2.base << endl;

    CSum * c3 = nullptr;
    c3->show(); // nullptr can access class member
    c3->showBase();

    CSum c4;
    c4.base = 20;
    c4.testConst(5);
    c4.testConst(3,5);

    const CSum c5{};
//    c5.base = 7; cannot do this since c5 is a const object (equal const Csum * const this)
    c5.testConst(6);
    // const object can only call const function
//    c5.show();
//    c5.testConst(3,5);

    Building blt;
    friendBuilding(& blt);

    goodFriend gf;
    gf.visit();

    goodFriend gf1(& blt);
    gf.visit();

    blt.sRoom = "kitchen";
    GF gf3(blt);
    gf3.visit();
    gf3.visit1();

    A a1;
    a1.a = 5;
    a1.b = 5;

    A a2;
    a2.a = 3;
    a2.b = 4;

    A a3 = a1.addA(& a2);
    a3.show();

    // reload operator + as a new definition
    A a4 = a1 + a2;
    a4.show();

    A a5 = a1 + a2;
    a5.show();

    A a6 = a1 + 1;
    a6.show();

    // reload << operator
    cout << a6 << " test " << endl;

    cout << a6++.a << endl;
    cout << a6.a << endl;
    cout << ++a6.a << endl;

    A a7;
    a7.a = 5;
    a7.b = 5;

    flag = a1 == a7;
    cout << "a1 == a7 => " << flag << endl;
    flag = a2 == a7;
    cout << "a2 == a7 => " << flag << endl;
    flag = a2 != a7;
    cout << "a2 != a7 => " << flag << endl;

    for(int i=1; i<5; ++(++i)) {
        printf("%s\n", to_string(i).c_str());
    }

    Son son1;
    cout << son1.a << son1.b << son1.Base::a << endl;
    son1.func();
    son1.Base::func();

    Son * son2 = new Son;
    son2->func();
    son2->Base::func();
    delete son2;

    D ddd;
    ddd.B::b = -1;
    ddd.C::b = -2;
    cout << ddd.a << ddd.b << endl;

    Cat cat("Tom");
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);

    Animal animal;
    doSpeak(animal);

    Animal * animal1 = new Cat("Tom");
    animal1->speak();
    delete animal1;

    testCalc();

    testComputer();

    testFileIo();

    auto ** aaaaa = new Animal* [2];
    aaaaa[0] = new Cat("Tom");
    aaaaa[1] = new Dog;

    aaaaa[0]->speak();
    aaaaa[1]->speak();

    for(int i=0; i<2; ++i) {
        delete aaaaa[i];
    }

    delete[] aaaaa;

    cout << "delete []" << endl;

    ifstream ifs;
    int sid;
    string name;
    int dept_id;
    char buf[1024];
    ifs.open("../test1.txt", ios::in);
//    while (ifs >> sid && ifs >> name && ifs >> dept_id) {
//        cout << sid << name << dept_id << endl;
//    }
//    while (ifs.getline(buf, sizeof(buf))) {
//        string ssss = string(buf);
//        cout << "test io " << ssss << endl;
//        strtok(buf, " ");
//    }

    system("sleep 1"); // call shell
    return 0;
}

void test1() {
    Person ps("alex", 18);
    cout << ps.name.c_str() << " " << *ps.age << endl;

    Person ps1 = Person(ps);
    cout << ps1.name.c_str() << " " << *ps1.age << endl;

    Person ps3;
    cout << ps.height << ps3.height << endl;
    ps1.height = 8;
    cout << ps.height << ps3.height << endl;
    cout << Person::height << endl;
    Person::show(); // call static function


    A a7;
    a7.d = new int(99);
    cout << a7.d << endl;

    A a8;
    a8.d = new int(100);
    cout << a8.d << endl;

    cout << *a7.d << " " << *a8.d << endl;
    a8 = a7; // shallow copy when a7 obj destruct will raise error for a8 | we overload = to avoid
    cout << a7.d << endl;
    cout << a8.d << endl;
    cout << *a7.d << " " << *a8.d << endl;
}

int & funcAsLeftVal() {
    static int a = 10;
    return a;
}

int myMax(int a, int b) {
    return a > b ? a : b;
}
