#include <string>
#include <iostream>
#include "fileOperations.h"


using namespace std;


void fileOperation::Save2File(Player& p) {
	PFile.open(P_file_name, std::ofstream::out | std::ofstream::trunc);
	PFile.close();
	PFile.open(P_file_name);
	PFile << "Player Name: " << p.getName() << endl;
	PFile << "Max HP: " << p.getMaxHP() << endl;
	PFile << "CUrrent HP: " << p.getHP() << endl;
	PFile << "Attack Damage: " << p.getDMG() << endl;
	PFile << "Currency: " << p.getCurrency() << endl;
}
//Function Saves player progress into a file


void fileOperation::Save2File(scoreBoard& s) {
	PFile << "Scoreboard Name: " << s.getName() << endl;
	PFile << "Score: " << s.getScore() << endl;
	PFile << "Difficulty: " << s.getDiff() << endl;
	PFile << "Floor: " << s.getFloor();
}
//Function Saves scoreboard progress into a file


void fileOperation::ChooseFile(scoreBoard& s, Player& p) {
	string answer, DonCare;
	string name, difficulty, WN = " ";
	int MaxHealth, health, DMG, gold, score, fl, i;
	cout << "Do you have an existing file?   " << endl;
	cout << "Please Enter [Yes] or [No]" << endl;
	cin >> answer;

	if (answer == "Yes") {
		cout << "Please enter the file name to open the file:  ";
		cin >> P_file_name;
		PFile.open(P_file_name);
		if (PFile.fail()) {
			cerr << "The file can not be founded." << endl;
			exit(1);
		}//if

			cout << "Imported player information from the file: " << endl;
			PFile >> DonCare >> DonCare >> name;
			p.setName(name);
			cout << "Player Name:  " << p.getName() << endl;
			PFile >> DonCare >> DonCare >> MaxHealth;
			p.setMaxHP(MaxHealth);
			cout << "Max Health: " << p.getMaxHP() << endl;
			PFile >> DonCare >> DonCare >> health;
			p.setHP(health);
			cout << "Current HP: " << p.getHP() << endl;
			PFile >> DonCare >> DonCare >> DMG;
			p.setDMG(DMG);
			cout << "Attack Damage: " << p.getDMG() << endl;
			PFile >> DonCare >> gold;
			p.setCurrency(gold);
			cout << "Currency: " << p.getCurrency() << endl;

			PFile >> DonCare >> DonCare >> name;
			s.setName(name);
			cout << "Name on Scoreboard: " << s.getName() << endl;
			PFile >> DonCare >> score;
			s.setScore(score);
			cout << "Score: " << s.getScore() << endl;
			PFile >> DonCare >> difficulty;
			s.setDiff(difficulty);
			cout << "Difficulty Level: " << s.getDiff() << endl;
			PFile >> DonCare >> fl;
			s.setFloor(fl);		
			cout << "Current Floor: " << s.getFloor() << endl;
	}//if


	else if (answer == "No") {
		cout << "What is your name?  ";
		cin >> name;
		p.setName(name);
		s.setName(name);
		P_file_name = name + ".txt";
		PFile.open(P_file_name, ios::out);
		cout << "File created successfully!." << endl;
		cout << "A file named " << P_file_name << " has been created for you." << endl << endl;;
	}


}//Function that asks the user to select the file to use


void fileOperation::CloseFile() {
	SBFile.close();
	PFile.close();

}//Function to close the files


void fileOperation::ScoreRank() {
	string donCare, name, score;
	//SBFile.open(SB_file_name);


	while (SBFile) {
		SBFile >> donCare >> score >> donCare >> name;
		cout << "Player: " << name << "\t" << "Score: " << score << endl;
		}//while
	
}//Function to output scores from all the scoreboards

