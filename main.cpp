#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <csignal>
#include "map.h"
using namespace std;

bool isLooping = true;
void cancelLoop(int signum) {
    isLooping = false;
    cout << endl << "EXITING...";
}

int main() {
    signal(SIGINT, cancelLoop);
    Robot robot;
    Kecoak kecoak;
    Map map;
    srand((unsigned) time(0));
    while (robot.health > 0 & isLooping) {
        system("cls");
        if(rand() % 2 + 1 == 2) map.spawn(&kecoak, &robot);
        map.plot(&kecoak, &robot);
        map.status(&kecoak, &robot);
        robot.cmd(&kecoak);
        kecoak.shoot(&robot);
    }
    system("cls");
    robot.status(0);
}
