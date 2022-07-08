//
// Created by Yang,Xi on 6/25/22.
//

#ifndef LEARN_POINTER_H
#define LEARN_POINTER_H

#include "istream"
#include "math.h"

using namespace std;


class Pointer {
private:
    float x;
    float y;

public:
    Pointer(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Pointer() {
    }

    virtual ~Pointer() {
        printf("this is pointer deconstructor call.  %p\n", this);
    }

    void setCoordinate(int x, int y) {
        this->x = x;
        this->y = y;
    }

    tuple<int, int> getCoordinate() const {
        return make_tuple(this->x, this->y);
    }
};

class Round {
private:
    float r;
    float center_x;
    float center_y;

public:
    void setR(int r) {Round::r = r;}

    int getR() {return r;}

    void setC(int x, int y) {
        tie(Round::center_x, Round::center_y) = make_tuple(x, y);
    }

    tuple<int, int> getC() {return make_tuple(center_x, center_y);}

    int checkPointInRound(Pointer & p) {
        float p_x;
        float p_y;
        tie(p_x, p_y) = p.getCoordinate();

        float dis = sqrt(pow(p_x - center_x, 2) + pow(p_y - center_y, 2));

        if (dis == r) {
            return 0;
        } else if (dis > r) {
            return 1;
        } else {
            return -1;
        }
    }
};


#endif //LEARN_POINTER_H
