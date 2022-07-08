//
// Created by Yang,Xi on 6/27/22.
//

#ifndef LEARN_PHONE_H
#define LEARN_PHONE_H
#include <utility>

#include "string"
#include "iostream"

using namespace std;

class Chip {
public:
    string brand;
    int gen;

    Chip(string brand, int gen): brand(move(brand)), gen(gen) {}
};

class Phone {
public:
    string brand;
    Chip chip;

    Phone(string brand, string chip_brand, int chip_gen):
    brand(move(brand)), chip(move(chip_brand), chip_gen) {}
};


#endif //LEARN_PHONE_H
