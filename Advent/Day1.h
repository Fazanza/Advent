#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void day1() {
    int curMaximum = 0;
    int curValue = 0;
    priority_queue<int, vector<int>, greater<int>> g;
    string temp;

    ifstream ins;
    ins.open("input.txt");
    while (getline(ins, temp)) {
        if (temp != "") {
            curValue += stoi(temp);
        }
        else {
            if (g.size() < 3) {
                g.push(curValue);
            }
            else if (curValue > g.top()) {
                g.pop();
                g.push(curValue);
            }
            curValue = 0;
        }
    }

    while (!g.empty()) {
        curMaximum += g.top();
        g.pop();
    }

    cout << curMaximum;
}
