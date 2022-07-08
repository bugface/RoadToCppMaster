//
// Created by Yang,Xi on 7/6/22.
//

#ifndef STAFFMANAGEMENTSYSTEM_STAFF_H
#define STAFFMANAGEMENTSYSTEM_STAFF_H
#pragma once
#include <utility>

#include "string"
#include "iostream"

using namespace std;

class staff {
protected:
    int sid;
    string name;
    int dept_id;

public:
    int getStaffID() {
        return this->sid;
    }

    int getDeptID() {
        return this->dept_id;
    }

    string getStaffName() {
        return this->name;
    }

    virtual ~staff() = default;
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;
};


class worker : public staff {
public:
    worker(int sid, string name, int did) {
        this->sid = sid;
        this->name = move(name);
        this->dept_id = did;
    }

    ~worker() override = default;;

    void showInfo() override {
        printf("staff id: %d\nstaff name: %s\nstaff dept: %s\ntask: do the work from manager\n",
               this->sid, this->name.c_str(), this->getDeptName().c_str());
    }

    string getDeptName() override {
        return {"worker"};
    }
};

class manager : public staff {
public:
    manager(int sid, string name, int did) {
        this->sid = sid;
        this->name = move(name);
        this->dept_id = did;
    }

    ~manager() override = default;

    void showInfo () override {
        printf("staff id: %d\nstaff name: %s\nstaff dept: %s\ntask: take task from boss and give to workers\n",
               this->sid, this->name.c_str(), this->getDeptName().c_str());
    }

    string  getDeptName() override {
        return {"manager"};
    }
};


class boss : public staff {
public:
    boss(int sid, string name, int did) {
        this->sid = sid;
        this->name = move(name);
        this->dept_id = did;
    }

    ~boss() override = default;

    void showInfo () override {
        printf("staff id: %d\nstaff name: %s\nstaff dept: %s\ntask: operate the company.\n",
               this->sid, this->name.c_str(), this->getDeptName().c_str());
    }

    string  getDeptName() override {
        return {"boss"};
    }
};

#endif //STAFFMANAGEMENTSYSTEM_STAFF_H
