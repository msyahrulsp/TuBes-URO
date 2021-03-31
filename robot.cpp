#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "robot.h"

Robot::Robot() {
    this->health = 10;
    this->damage = 4;
    this->range = 4;
    this->killCount = 0;
    this->pos = {0,0};
}

void Robot::cmd(Kecoak *kecoak) {
    int cmd;
    cout << "Apa yang ingin anda lakukan?" << endl << "1. Bergerak" << endl << "2. Menembak" << endl;
    cout << "Pilihan anda >> ";
    cin >> cmd;

    if (cmd == 1) {
        this->move(kecoak);
    } else if (cmd == 2) {
        this->shoot(kecoak);
    }
}

void Robot::status(int type) {
    cout << "--ROBOT STATS--" << endl;
    if (type==1) cout << "Current Health : " << this->health << endl;
    cout << "Weapon Range : " << this->range << endl; 
    cout << "Weapon Damage : " << this->damage << endl;
    cout << "Kill Count : " << this->killCount << endl;
}

bool Robot::validMove(Kecoak *kecoak, int type) {
    vector<vector<int>> temp = this->getNearKecoak(kecoak);
    for (int i=0;i < temp.size(); i++) {
        if (type == 1) {
            if((this->pos[1]+1 == temp[i][1]) & (this->pos[0] == temp[i][0])) return false; 
        } else if (type == 2) {
            if((this->pos[0]+1 == temp[i][0]) & (this->pos[1] == temp[i][1])) return false;
        } else if (type == 3) {
            if((this->pos[1]-1 == temp[i][1]) & (this->pos[0] == temp[i][0])) return false;
        } else {
            if((this->pos[0]-1 == temp[i][0]) & (this->pos[1] == temp[i][1])) return false;
        }
    }
    if(type == 3) {
        if(this->pos[1]-1 < 0) return false;
    } else if (type == 4) {
        if(this->pos[0]-1 < 0) return false;
    }
    return true;
}

void Robot::move(Kecoak *kecoak) {
    int cmd;
    cout << endl << "Kemana anda ingin aku bergerak?" << endl << "1. Maju" << endl << "2. Kanan" << endl << "3. Mundur" << endl << "4. Kiri";
    cout << endl << "Pilihan anda >> ";
    cin >> cmd;
    if (cmd == 1 & (this->validMove(kecoak, 1) == true)) {
        this->pos[1] += 1;
    } else if (cmd == 2 & (this->validMove(kecoak, 2) == true)) {
        this->pos[0] += 1;
    } else if (cmd == 3 & (this->validMove(kecoak, 3) == true)) {
        this->pos[1] -= 1;
    } else if (cmd == 4 & (this->validMove(kecoak, 4) == true)) {
        this->pos[0] -= 1;
    } else {
        cout << "Aku tidak bisa menabrak dinding atau kecoak" << endl;
    }
}

void Robot::shoot(Kecoak *kecoak) {
    cout << endl;
    for (int i=0;i < kecoak->pos.size();i++) {
        int x = kecoak->pos[i][0];
        int y = kecoak->pos[i][1];
        if (checkDistance(x, y)) {
            kecoak->despawn(i);
            this->killCount += 1;
            cout << "--ROBOT DAMAGE LOG--" << endl << "Robot -> Kecoak " << i+1 << " = " << this->damage << " damage" << endl;
            break;
        } else {
            cout << "Senjata tidak dapat mencapai kecoak pada koordinat (" << x << ", " << y << ")" << endl;
        }
    }
}

bool Robot::checkDistance(int x, int y) {
    int temp1 = abs(this->pos[0] - x);
    int temp2 = abs(this->pos[1] - y);
    if (sqrt(pow(temp1, 2) + pow(temp2, 2)) <= this->range) return true;
    return false;
}

double Robot::getDistance(int x, int y) {
    int temp1 = abs(this->pos[0] - x);
    int temp2 = abs(this->pos[1] - y);
    return(sqrt(pow(temp1, 2) + pow(temp2, 2)));    
}

vector<vector<int>> Robot::getNearKecoak(Kecoak *kecoak) {
    vector<vector<int>> temp;
    for (int i=0; i < kecoak->pos.size(); i++) {
        int x = kecoak->pos[i][0];
        int y = kecoak->pos[i][1];
        if (checkDistance(x, y)) {
            temp.push_back({x, y});
        }
    }
    return temp;
}