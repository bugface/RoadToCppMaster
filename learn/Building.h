//
// Created by Yang,Xi on 6/29/22.
//

#ifndef LEARN_BUILDING_H
#define LEARN_BUILDING_H
#include "iostream"
#include "string"

using namespace std;

class Building;

class GF {
public:
    Building * b;
    GF(Building & b){
        this->b = & b;
    };
    // we do not want to add GF as friend class but visit function as friend function
    void visit();

    void visit1();
};

class goodFriend {
public:
    Building * b;

    goodFriend();

    goodFriend(Building * b);

    void visit() const;
};


class Building {
    friend void friendBuilding(Building * b); // friend function
    friend class goodFriend; // friend function
    friend void GF::visit1(); // class field function as friend

public:
    string sRoom;

    Building() {
        this->sRoom = "living";
        this->bRoom = "bed";
    }

private:
    string bRoom;
};

// global function
// we want a func to visit both public and private variable in Building class
// we need to declare the function in the class with "friend" keywords
// then this function will be able to access the private fields of the class
void friendBuilding(Building *b) {
    printf("visit %s and %s through friend function. \n", b->sRoom.c_str(), b->bRoom.c_str());
}

goodFriend::goodFriend() {
    this->b = new Building;
}

goodFriend::goodFriend(Building * b) {
    this->b = b;
}

void goodFriend::visit() const {
    printf("visit %s and %s through good friend class. \n", this->b->sRoom.c_str(), this->b->bRoom.c_str());
}

void GF::visit() {
    printf("visit %s and %s through friend function. \n", this->b->sRoom.c_str());
};

void GF::visit1() {
    printf("visit %s and %s through good friend class. \n", this->b->sRoom.c_str(), this->b->bRoom.c_str());
};

#endif //LEARN_BUILDING_H
