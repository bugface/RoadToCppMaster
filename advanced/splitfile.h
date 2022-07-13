//
// Created by alex on 7/12/22.
//

#ifndef ADVANCED_SPLITFILE_H
#define ADVANCED_SPLITFILE_H
#include <iostream>
#include <string>

using namespace std;

template <class T>
class splitfile {
public:
    T t;

    splitfile(T t);

    void show();
};

#endif //ADVANCED_SPLITFILE_H
