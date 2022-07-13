//
// Created by alex on 7/12/22.
//

#ifndef ADVANCED_FRIENDTEMPLATE_H
#define ADVANCED_FRIENDTEMPLATE_H
#include <iostream>
#include <string>

using namespace std;

// we need to let compiler know in prior about the class and the friend function
template <typename T1, typename T2>
class FriendTemplate;

template <class T1, class T2>
void show(FriendTemplate<T1, T2> &ft) {
    cout << ft.name << " " << ft.age << endl;
}
//********************************************************************

template <typename T1, typename T2>
class FriendTemplate {

friend void show<>(FriendTemplate<T1, T2> &ft);

public:
    FriendTemplate(T1 name, T2 age) {
        this->name = name;
        this->age = age;
    }

private:
    T1 name;
    T2 age;
};

void testFriendTemplate() {
    FriendTemplate<string, double> ft = {"alex" , 20.0};
    show(ft);
}

#endif //ADVANCED_FRIENDTEMPLATE_H
