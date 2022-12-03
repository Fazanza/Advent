#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int rockScore = 1;
const int paperScore = 2;
const int scissorScore = 3;
const int win = 6;
const int draw = 3;
const int lose = 0;
const char rock = 'A';
const char paper = 'B';
const char scissor = 'C';
const char loseChar = 'X';
const char drawChar = 'Y';
const char winChar = 'Z';

void Day2() {
	char other;
	char me;
	int score = 0;
	ifstream ins;

	ins.open("inputDay2.txt");
	while(ins >> other >> me) {
		if (other == rock) {
			if (me == winChar) {
				score += (win + paperScore);
			}
			else if (me == drawChar) {
				score += (draw + rockScore);
			}
			else if (me == loseChar) {
				score += (lose + scissorScore);
			}

		} else if(other == paper){
			if (me == winChar) {
				score += (win + scissorScore);
			}
			else if (me == drawChar) {
				score += (draw + paperScore);
			}
			else if (me == loseChar) {
				score += (lose + rockScore);
			}
		} else if(other == scissor){
			if (me == winChar) {
				score += (win + rockScore);
			}
			else if (me == drawChar) {
				score += (draw + scissorScore);
			}
			else if (me == loseChar) {
				score += (lose + paperScore);
			}
		}
	}

	cout << score;
}
