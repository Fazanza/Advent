#pragma once
#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;

void day3(){
	ifstream ins;
	string item;
	string item2;
	string item3;
	ins.open("inputEthanDay3.txt");
	int sum = 0;

	unordered_map<char, int> map;
	unordered_map<char, int> map2;
	while(ins >> item >> item2 >> item3){
		for (int i = 0; i < item.size(); i++) {
			map[item[i]] = 1;
		}

		for (int j = 0; j < item2.size(); j++) {
			if (map.find(item2.at(j)) != map.end()) {
				map2[item2[j]] = 1;
			}
		}

		for (int k = 0; k < item3.size(); ++k) {
			if (map2.find(item3.at(k)) != map2.end()) {
				if (isupper(item3.at(k))) {
					sum += (item3.at(k) - 'A') + 27;
				}
				else {
					sum += (item3.at(k) - 'a') + 1;
				}
				break;
			}
		}

		map.clear();
		map2.clear();
	}

	cout << sum << "\n";
}