//
// Created by alex on 7/21/22.
//

#include "RefScore.h"

Player::Player(string name, int score) {
    this->name = name;
    this->score = score;
}

void printVector(vector<Player> &v) {
    for (const Player &p: v) {
        cout << p.name << " " << p.score << endl;
    }
}

void addPlayer(vector<Player> &v) {
    for (int i = 0; i < 5; ++i) {
        string name = "name_" + to_string(i + 1);
        int score = 0;
        Player p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Player> &v) {
    srand(time(nullptr));
    deque<int> dq;
    for (auto it = v.begin(); it < v.end(); ++it) {
        for (int i = 0; i < 10; ++i) {
            int score = (int) random() % 41 + 60;
            dq.push_back(score);
        }

        sort(dq.begin(), dq.end());
        cout << it->name << " get scores: " << endl;
        for (auto dq_it = dq.begin(); dq_it < dq.end(); ++dq_it) {
            cout << *dq_it << " ";
        }
        cout << endl;

        // remove max and min
        dq.pop_front();
        dq.pop_back();

        int sum = 0;
        for (auto dq_it = dq.begin(); dq_it < dq.end(); ++dq_it) {
            sum += *dq_it;
        }

        it->score = sum / (int) dq.size();

        dq.clear();
    }
}

void runRefScore() {
    vector<Player> v;
    addPlayer(v);
    setScore(v);
    printVector(v);
}