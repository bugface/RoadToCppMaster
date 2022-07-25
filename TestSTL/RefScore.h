//
// Created by alex on 7/21/22.
//

#ifndef TESTSTL_REFSCORE_H
#define TESTSTL_REFSCORE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <algorithm>

using namespace std;

class Player {
public:
    string name;
    int score;

    Player(string name, int score);
};

void printVector(vector<Player> &v);

void addPlayer(vector<Player> &v);

void setScore(vector<Player> &v);

void runRefScore();


#endif //TESTSTL_REFSCORE_H
