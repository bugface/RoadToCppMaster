//
// Created by alex on 8/14/22.
//

#ifndef COMPUTERROOMRESERVATION_IDENTITY_HPP
#define COMPUTERROOMRESERVATION_IDENTITY_HPP

#pragma once

#include <iostream>

using namespace std;

class Identity {
public:
    string name;
    string pwd;

    virtual void operMenu() = 0;
};


#endif //COMPUTERROOMRESERVATION_IDENTITY_HPP
