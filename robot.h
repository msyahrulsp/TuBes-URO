#ifndef ROBOT_H
#define ROBOT_H
#include <vector>
#include "kecoak.h"
using namespace std;

class Robot {
    public:
        class Kecoak *kecoak;
        int health, damage, range, killCount;
        vector<int> pos;
        Robot();
        void cmd(Kecoak *kecoak);
        void status(int type);
        bool validMove(Kecoak *kecoak, int type);
        void move(Kecoak *kecoak);
        void shoot(Kecoak *kecoak);
        bool checkDistance(int x, int y);
        double getDistance(int x, int y);
        vector<vector<int>> getNearKecoak(Kecoak *kecoak);
};

#endif