#include <iostream>
#include <math.h>
#include <windows.h>
#include "kecoak.h"

Kecoak::Kecoak() {
    this->health = 2;
    this->damage = 2;
    this->range = 2;
}

void Kecoak::spawn(int x, int y) {
    this->pos.push_back({x, y});
}

void Kecoak::despawn(int n) {
    this->pos.erase(pos.begin() + n);
}

void Kecoak::shoot(Robot *robot) {
    cout << endl << "--KECOAK DAMAGE LOG--" << endl;
    for (int i=0; i < this->pos.size(); i++) {
        int x = this->pos[i][0];
        int y = this->pos[i][1];
        int x1 = robot->pos[0];
        int y1 = robot->pos[1];
        if (checkDistance(x, y, x1, y1)) {
            robot->health -= this->damage;
            cout << "Kecoak " << i+1 << " -> Robot = " << this->damage << " damage" << endl;;
            if (robot->health <= 0) {
                break;
            }
        }
    }
    Sleep(1000);
}

bool Kecoak::checkDistance(int x, int y, int x1, int y1) {
    int temp1 = abs(x1 - x);
    int temp2 = abs(y1 - y);
    if (sqrt(pow(temp1, 2) + pow(temp2, 2)) <= this->range) return true;
    return false;
}