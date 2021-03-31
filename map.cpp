#include <iostream>
#include "map.h"

using namespace std;

void Map::spawn(Kecoak *kecoak, Robot *robot) {
    int x = rand() % 5;
    int y = rand() % 5;
    while ((x == robot->pos[0]) && (y == robot->pos[1])) {
        x = rand() % 5;
        y = rand() % 5;
    }
    kecoak->spawn(x, y);
}

void Map::status(Kecoak *kecoak, Robot *robot) {
    robot->status(1);
    cout << endl << "--KECOAK POSITION--" << endl;
    if (!kecoak->pos.empty()) {
        for (int i=0;i < kecoak->pos.size();i++) {
            int x = kecoak->pos[i][0];
            int y = kecoak->pos[i][1];
            cout << "Kecoak " << i + 1 << " [Health : " << kecoak->health << ", WR : " << kecoak->range << "] : (" << x << ", " << y << ")"; 
            cout << " -> Jarak : " << robot->getDistance(x, y);
            if (robot->getDistance(x,y) <= kecoak->range) cout << " (Bisa menembakku)";
            cout << endl;
        }
    } else {
        cout << "TIDAK ADA KECOAK" << endl;
    }
    cout << endl;
}

void Map::plot(Kecoak *kecoak, Robot *robot) {
    vector<vector<int>> nearKecoak = robot->getNearKecoak(kecoak);
    cout << "--MAP ROBOT--" << endl;
    for (int i=robot->pos[1]+4;i >= robot->pos[1]-4; i--) {
        for (int j=robot->pos[0]-4;j <= robot->pos[0]+4; j++) {
            for (int k=0; k < nearKecoak.size(); k++) {
                if (nearKecoak[k][0] == j & nearKecoak[k][1] == i) {
                    cout << "K";
                }
            }
            if(i < 0 | j < 0) {
                cout << "*";
            } else if(i == robot->pos[1] & j == robot->pos[0]) {
                cout << "R";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "Current Position : (" << robot->pos[0] <<", " << robot->pos[1] << ")" << endl << endl;
}
