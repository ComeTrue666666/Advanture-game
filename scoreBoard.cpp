#include <string>
#include <iostream>
#include "scoreBoard.h"
#include <iomanip>
#include <fstream>

using namespace std;

scoreBoard::scoreBoard() {
	SBName = "NewPlayer";
	SBScore = 0;
	SBDifficulty = "Eeay";
	difficultyMod = 1;
	SB_floor = 1;
}

scoreBoard::scoreBoard(string name, int score) {
	SBName = name;
	SBScore = score;
}

void scoreBoard::setName(string name) {
	SBName = name;
}

void scoreBoard::setScore(int score) {
	SBScore = score;
}

void scoreBoard::setDiff(string d) {
	SBDifficulty = d;
}

void scoreBoard::setDiffMod(int mod) {
	difficultyMod = mod;
}

void scoreBoard::setFloor(int fl) {
	SB_floor = fl;
}

string scoreBoard::getName() {
	return SBName;
}

int scoreBoard::getScore() {
	return SBScore;
}

string scoreBoard::getDiff() {
	return SBDifficulty;
}

int scoreBoard::getDiffMod() {
	return difficultyMod;
}

int scoreBoard::getFloor() {
	return SB_floor;
}

void scoreBoard::addScore(int score) {
	SBScore += score;
}

void scoreBoard::SB_out() {
	cout << "Player Name:  " << getName() << endl;
	cout << "Score:  " << getScore() << endl;
	cout << "Difficulty:  " << getDiff() << endl;
	cout << "Floor:   " << getFloor() << endl << endl;
}

//void operator << (ostream& os, const scoreBoard& p) {
//	os << p.SBName  << setw(20) << p.SBScore << endl;
//}


bool scoreBoard::operator < (const scoreBoard& s1) {
	return SBScore > s1.SBScore;
}


//bool scoreBoard::operator ()(const scoreBoard& player1, const scoreBoard& player2) {
//	return player1.SBName < player2.SBName;
//	}




