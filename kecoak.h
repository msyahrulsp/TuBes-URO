#ifndef KECOAK_H
#define KECOAK_H
#include <vector>
#include "robot.h"
using namespace std;

class Kecoak {
    public:
        class Robot *robot;
        int health, damage, range;
        vector<vector<int>> pos;
        Kecoak();
        void spawn(int x, int y);
        void despawn(int n);
        void shoot(Robot *robot);
        vector<vector<int>> getNearPos(Robot *robot);
        bool checkDistance(int x, int y, int x1, int y1);
};

#endif