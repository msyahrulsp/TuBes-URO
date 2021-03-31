#ifndef MAP_H
#define MAP_H
#include "robot.h"
#include "kecoak.h"

using namespace std;

class Map {
    public:
        class Kecoak *kecoak;
        class Robot *robot;
        void spawn(Kecoak *kecoak, Robot *robot);
        void status(Kecoak *kecoak, Robot *robot);
        void plot(Kecoak *kecoak, Robot *robot);
};

#endif