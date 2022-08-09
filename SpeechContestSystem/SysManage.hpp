//
// Created by alex on 8/7/22.
//

#ifndef SPEECHCONTESTSYSTEM_SYSMANAGE_HPP
#define SPEECHCONTESTSYSTEM_SYSMANAGE_HPP
#pragma once

#include <random>
#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "speaker.h"
#include <deque>
#include <fstream>
#include <filesystem>

using namespace std;

class SysManage {
    /*
     * control UI
     * control speech contest workflow
     * control io
     */
public:
    map<int, Speaker> id2speaker;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    int roundIdx;
    int numSpeakers = 12;
    int IdShift = 10001;
    bool recordIsEmpty = true;
    map<int, vector<vector<string>>> record;

    SysManage() {
        this->initContest();
        this->loadRecords();
    }

    ~SysManage() = default;

    static void showMenu();

    static void exitSystem();

    void initContest();

    void createSpeaker();

    void speechDraw();

    void startSpeechContest();

    void speechContest();

    void printMap();

    void printVec(const vector<int> &v);

    void saveRecords();

    void loadRecords();

    void showHistory();

    void cleanRecord();
};

void SysManage::showMenu() {
    cout << "*********************************************" << endl;
    cout << "*** welcome to the speech contest ***" << endl;
    cout << "1. start contest" << endl;
    cout << "2. check historical records" << endl;
    cout << "3. clear contest results" << endl;
    cout << "0. quit" << endl;
}

void SysManage::exitSystem() {
    cout << "All done! Bye!";
    exit(0);
}

void SysManage::initContest() {
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->id2speaker.clear();
    this->roundIdx = 1;
    this->record.clear();
    this->recordIsEmpty = true;
}

void SysManage::createSpeaker() {
    for (int i = 0; i < this->numSpeakers; ++i) {
        Speaker s;
        s.name = "speaker_" + to_string(i + 1);
        for (double &score: s.scores) {
            score = 0.0;
        }
        int newID = i + this->IdShift;
        this->id2speaker.insert(make_pair(newID, s));
        this->v1.push_back(newID);
    }
}

void SysManage::speechDraw() {
    cout << "current is " << this->roundIdx << " round drawing process..." << endl;
    cout << "------------------" << endl;
    vector<int> v;
    if (this->roundIdx == 1) {
        shuffle(this->v1.begin(), this->v1.end(), mt19937(random_device()()));
        v = v1;
    } else {
        shuffle(this->v2.begin(), this->v2.end(), mt19937(random_device()()));
        v = v2;
    }
    cout << "The determined order after drawing: " << endl;
    for (int idx: v) {
        cout << idx << " ";
    }
    cout << endl;
}

bool descending(int x, int y) {
    return x > y;
}

bool descendingDouble(double x, double y) {
    return x > y;
}

void SysManage::speechContest() {
    cout << "Speech Contest Round : " << this->roundIdx << " start..." << endl;

    vector<int> tmp;
    tmp = (this->roundIdx == 1) ? v1 : v2;

    vector<int> *toNextRound;
    toNextRound = (this->roundIdx == 1) ? &v2 : &v3;

    //make two group
    multimap<double, int, decltype(descendingDouble) *> group(descendingDouble);
    int groupCount = 0;

    for (auto idx: tmp) {
        groupCount++;
        deque<double> d;
        // give 10 scores for each speaker
        for (int i = 0; i < 10; ++i) {
            double score = (double) (random() % 401 + 600) / 10.f;
            d.push_back(score);
        }

        //sort
        sort(d.begin(), d.end(), descending);
        // remove max and min
        d.pop_back();
        d.pop_front();
        //get avg
        double avgSocres = accumulate(d.begin(), d.end(), 0.0) / 8.0;
        this->id2speaker.at(idx).scores[this->roundIdx - 1] = avgSocres;

        group.insert(make_pair(avgSocres, idx));
        // get top 3 for each group (6 people consist 1 group)
        if (groupCount % 6 == 0) {
            cout << "Group " << (groupCount / 6) << " scores:" << endl;
            for (const auto &it: group) {
                Speaker s = this->id2speaker[it.second];
                cout << s.name << " " << it.second;
                cout << " score: " << it.first << endl;
            }

            //get first 3 put to tmp
            int headCount = 3;
            for (auto it = group.begin(); headCount > 0; ++it, --headCount) {
                toNextRound->push_back(it->second);
            }

            group.clear();
        }
    }
    cout << "round " << this->roundIdx << " is finished.";
//    this->printMap();
}

void SysManage::startSpeechContest() {
    this->createSpeaker();
    // 1st round draw to create order (random shuffle)
    this->speechDraw();
    // 1st round contest to get score
    this->speechContest();
    // show results and decide who are advanced to the next round
    this->printVec(this->v2);
    // 2nd round contest draw
    this->roundIdx++;
    this->speechDraw();
    // 2nd round contest to get score
    this->speechContest();
    this->printVec(this->v3);
    // save results to file
    this->saveRecords();
    this->initContest();
    this->loadRecords();

    cout << "This contest is finished." << endl;
    cout << "-------------------------" << endl;
    cout << endl;
}

void SysManage::printMap() {
    for (const auto &it: this->id2speaker) {
        cout << "id: " << it.first << " name: " << it.second.name;
        cout << " score 1: " << it.second.scores[0];
        cout << " score 2: " << it.second.scores[1];
        cout << endl;
    }
}

void SysManage::printVec(const vector<int> &v) {
    cout << "round: " << this->roundIdx << " winner and their results." << endl;
    for (auto i: v) {
        Speaker s = this->id2speaker[i];
        double score = s.scores[this->roundIdx - 1];
        cout << i << " " << s.name << " " << score << endl;
    }
}

void SysManage::saveRecords() {
    ofstream ofs;
    filesystem::path fp = filesystem::current_path().parent_path() / "results.csv";


    ofs.open(fp.string(), ios::out | ios::app);

    for (auto idx: this->v3) {
        Speaker s = this->id2speaker[idx];
        ofs << idx << "," << s.name << "," << s.scores[this->roundIdx - 1] << "," << endl;
    }

    ofs.close();
    cout << "Results are saved." << endl;
    this->recordIsEmpty = false;
}

void SysManage::loadRecords() {
    ifstream ifs;
    filesystem::path fp = filesystem::current_path().parent_path() / "results.csv";
    ifs.open(fp, ios::in);

    if(! ifs.is_open()) {
        this->recordIsEmpty = true;
        cout << "No record find." << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if(ifs.eof()) {
        cout << "Record file is empty." << endl;
        this->recordIsEmpty = true;
        ifs.close();
        return;
    }

    this->recordIsEmpty = false;
    ifs.putback(ch);
    string data;
    int index = 0;
    int count = 0;
    vector<vector<string>> v;
    while(ifs >> data) {
        vector<string> vv;
        int pos = -1;
        int start = 0;
        while (true) {
            pos = data.find(',', start);
            if (pos == -1) break;
            string tmp = data.substr(start, pos - start);
            vv.push_back(tmp);
            start = pos + 1;
            count += 1;

            if (count % 3 == 0) {
                v.push_back(vv);
            }
        }

        if (count % 9 == 0) {
            vector<vector<string>> tmp1 = v;
            this->record.insert(make_pair((count / 9), tmp1));
            v.clear();
        }
    }
}

void SysManage::showHistory() {
    if (this->recordIsEmpty) {
        cout << "Cannot find history records." << endl;
    }

    for(auto &it: this->record) {
        cout << it.first << endl;
        for (auto &it1: it.second) {
            for (auto &it2: it1) {
                cout << it2 << " ";
            }
            cout << endl;
        }
    }
}

void SysManage::cleanRecord() {
    this->initContest();
    filesystem::path fp = filesystem::current_path().parent_path() / "results.csv";
    ofstream ofs(string(fp), ios::trunc);
    ofs.close();
    cout << "clean done!" << endl;
}

#endif //SPEECHCONTESTSYSTEM_SYSMANAGE_HPP
