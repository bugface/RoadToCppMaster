//
// Created by alex on 7/11/22.
//

#ifndef ADVANCED_TEMPLATECLASS_H
#define ADVANCED_TEMPLATECLASS_H

#include <iostream>
#include <string>

using namespace std;

template<typename NameType, typename AgeType = int> // typename can have default type value
class TemplateClass {
public:
    NameType name;
    AgeType age;

    TemplateClass() = default;

    TemplateClass(NameType name, AgeType age) {
        this->name = name;
        this->age = age;
    }

    void show() {
        cout << this->name << " " << this->age << endl;
    }
};

/*
 * following there are three methods to pass template class into a function call
 * In most cases, we use the first method, we use only class template and
 * clear state the class we want to pass into the function
 */

void printTemplateClass1(TemplateClass<string, int> &tc) {
    cout << "test pass template class obj into a function - clear define types: " << endl;
    tc.show();
}

template <typename T1, typename  T2> // tell function T1, T2 are two generic
void printTemplateClass2(TemplateClass<T1, T2> &tc) {
    cout << "test pass template class obj into a function - template types in function: " << endl;
    tc.show();
    cout << "T1: " << typeid(T1).name() << " T2: " << typeid(T2).name() << endl;
}

template <typename T>
void printTemplateClass3(T &tc) {
    cout << "test pass template class obj into a function - template whole class: " << endl;
    tc.show();
    cout << "T: " << typeid(T).name() << endl;
}

void testTemplageClass() {
    TemplateClass<string, int> tc1 = {"alex", 18};
    tc1.show();

    TemplateClass<int, double> tc2 = {18, 20.12};
    tc2.show();

    TemplateClass<string> tc3 = {"zhubajie", 20};
    tc3.show();
}


#endif //ADVANCED_TEMPLATECLASS_H
