#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Player.h"
#include "Enemy.h"
#include "fileOperations.h"
#include <list>
#include "Shop.h"
#include <stack>
#include <queue>

using namespace std;
using std::cout;
using std::cin;

bool quest1_flag = false, quest2_flag = false, quest3_flag = false;
bool enemyFlag = false;
int cumulative_damage = 0, cumulative_currency = 0, round_count = 0;

Player p1;
enemy e1;
scoreBoard s1;
fileOperation f1;
weapon currentWeapon, purchased;
vector <weapon> weaponList;

void EnemyCombat(enemy& e, Player& p, scoreBoard& s, vector <weapon> &w, list<scoreBoard>& SBList, stack<weapon>& tracker, Shop& shop, stack<enemy>& defeated, queue<string>&sideQuest, stack<int>& combatLog);
void PlayerCombat(Player&, enemy&, scoreBoard&, vector<weapon>&, stack<enemy> &defeated, list<scoreBoard>& SBList, stack<weapon>& tracker, Shop& shop, queue<string>&sideQuest, stack<int>& combatLog);
int PlayerOptions(Player&, scoreBoard&, vector <weapon>&, Shop&, stack<weapon>&, fstream& SBF);
void ChooseWeapon(vector <weapon>&, Player&);
void SBToList(fstream&, list<scoreBoard>&);
void searchList(list<scoreBoard>& l);
void operator << (const list<scoreBoard> l, int);
void insertionSort(fstream& f, scoreBoard s, list<scoreBoard>& l);
void averagedSB(list<scoreBoard>&, list<scoreBoard>&);
void addToStack(weapon removed, stack<weapon>& tracker);
void printStack(stack<weapon> tracker);
void clearStack(stack<weapon> &tracker);
void addToEnemyStack(enemy, stack<enemy>&);
void clearEnemyStack(stack<enemy>& defeated);
void mainMenu(fstream&, list<scoreBoard>&, list<scoreBoard>&, stack<weapon>&, stack<enemy>&, Shop&, enemy&, Player&, scoreBoard&, queue<string>&);
void QuitGame(list<scoreBoard>&, stack<weapon>&, stack<enemy>&, Shop&, enemy&);
void printSideQuest(queue<string>&);
void printCombatLog(stack<int>& combatLog, enemy& e);



int main() {

	fstream SBF;
	stack <enemy> defeated; 
	stack <weapon> shopTracker;		
	list <scoreBoard> SBList;
	list <scoreBoard> averagedList;
	queue <string> sideQuest;
	stack<int> combatLog;
	queue<enemy> enemyList;
	char diff;
	int output = 0, count = 0;
	string command, quest3 = "Quest 3: Kill an enemy in one round.", quest2 = "Quest 2: Cause 60 damage to enemies", 
		quest1 = "Quest 1: Save up 50 currency";
	Shop shop;
	weapon  Rock("Rock", 15, 1, 5), Knife("Knife", 25, 1, 10), Spear("Spear", 35, 1, 20),
		Sword("Sword", 45, 1, 30), Axe("Axe", 55, 1, 35), Gun("Gun", 70, 1, 40), Bomb("Bomb", 80, 1, 50);

	shop.addWeapon(new ShopNode(Rock));
	shop.addWeapon(new ShopNode(Knife));
	shop.addWeapon(new ShopNode(Spear));

	SBF.open("scoreboard.txt");
	f1.ChooseFile(s1, p1);
	SBToList(SBF, SBList);
	mainMenu(SBF, SBList, averagedList, shopTracker, defeated, shop, e1, p1, s1, sideQuest);
	SBF.seekg(0, ios::end);
	s1.setFloor(1);
	cout << "Please ENTER the EXACT word or character inside the [ ] when making choice in this Game!!!" << endl << endl;
	//if (s1.getFloor() >= 4) {
	//	cout << "You have reached floor 4  and defeated all the enemies! " << endl;
	//	cout << "Would you like to restart the game from floor 1? " << endl;
	//	cout << "Please enter [Yes] or [No]:  ";
	//	cin >> command;
	//	if (command == "Yes") {
	//		s1.setFloor(1);
	//		e1.setLvl(1);
	//		p1.setHP(p1.getMaxHP());
	//	}

	cout << "What difficulty level would you like to play?  " << endl;
	cout << "[E]asy\t[M]edium\t[D]ifficult." << endl;
	cin >> diff;
	cout << endl;

	if (diff == 'E') {
		s1.setDiff("Easy");
		s1.setDiffMod(2);
	}
	else if (diff == 'M') {
		s1.setDiff("Medium");
		s1.setDiffMod(3);
	}
	else if (diff == 'D') {
		s1.setDiff("Difficulty");
		s1.setDiffMod(4);
	}

	enemy Goblin("Goblin", 5 * s1.getDiffMod(), 2 * s1.getDiffMod(), 1, 15), Troll("Troll", 6 * s1.getDiffMod(), 3 * s1.getDiffMod(), 2, 20),
		Orc("Orc", 7 * s1.getDiffMod(), 4 * s1.getDiffMod(), 3, 25), Pikachu("Pikachu", 8 * s1.getDiffMod(), 5 * s1.getDiffMod(), 4, 40);
	enemyList.push(Goblin);
	enemyList.push(Troll);
	enemyList.push(Orc);
	enemyList.push(Pikachu);
	//e1.setMaxHP(e1.getMaxHP() * s1.getDiffMod());
	//e1.setHP(e1.getHP() * s1.getDiffMod());
	//e1.setDMG(e1.getDMG() * s1.getDiffMod());
	//e1.setLvl(1);
	//e1.setBounty(e1.getBounty() * s1.getDiffMod());
	p1.setHP(50);
	p1.setMaxHP(50);

	while (1) {
		if (s1.getFloor() > 4) {
			cout << "Congratulation!! You have defeated all the enemies!!" << endl << endl;
			f1.Save2File(p1);
			f1.Save2File(s1);
			printSideQuest(sideQuest);
			insertionSort(SBF, s1, SBList);
			cout << endl << "Scoreboard: " << endl;
			for (auto v : SBList) {
				cout << "Player Name: " << v.getName() << setw(30) << "Score: " << v.getScore() << endl;
			}
			QuitGame(SBList, shopTracker, defeated, shop, e1);
		}

		if (s1.getFloor() == 1) {
			cout << "You have a new Quest:" << endl;
			cout << quest1 << endl;
			cout << "Reward: 30 scores." << endl << endl;
		}

		else if (s1.getFloor() == 2) {
			cout << "You have a new Quest:" << endl;
			cout << quest2 << endl;
			cout << "Reward: 50 scores." << endl << endl;
		}
		else if (s1.getFloor() == 3) {
			cout << "You have a new Quest:" << endl;
			cout << quest3 << endl;
			cout << "Reward: 70 scores." << endl << endl;
		}

		while (1) {
			output = PlayerOptions(p1, s1, weaponList, shop, shopTracker, SBF);
			if (output != 0)
				break;
		}
		switch (output) {
		case 1:
			e1 = enemyList.front();
			combatLog.push(p1.getMaxHP());
			combatLog.push(e1.getEnemyMaxHP());
			cout << "A " << e1.getEnemyName() << " blocks your road." << endl << endl;
			EnemyCombat(e1, p1, s1, weaponList, SBList, shopTracker, shop, defeated, sideQuest, combatLog);
			PlayerCombat(p1, e1, s1, weaponList, defeated, SBList, shopTracker, shop, sideQuest, combatLog);
			enemyList.pop();
			count = 0;
			printCombatLog(combatLog, e1);
			
			break;
		case 2:
			mainMenu(SBF, SBList, averagedList, shopTracker, defeated, shop, e1, p1, s1, sideQuest);
			continue;
			break;
		}
		
		if (s1.getFloor() >= 1 && quest1_flag == false && cumulative_currency >= 50) {
			sideQuest.push(quest1);
			quest1_flag = true;
			s1.addScore(30);
		}
		
		if (s1.getFloor() >= 2 && quest2_flag == false && cumulative_damage >= 60) {
			sideQuest.push(quest2);
			quest2_flag = true;
			s1.addScore(50);
		}

		if (s1.getFloor() >= 3 && quest3_flag == false && round_count == 1) {
			sideQuest.push(quest3);
			quest3_flag = true;
			s1.addScore(70);
		}
		//e1.setMaxHP(e1.getMaxHP() + 5);
		//e1.setHP(e1.getMaxHP() + 5);
		//e1.setLvl(e1.getLvl() + 1);
		//e1.setDMG(e1.getDMG() + 2);
		//e1.setBounty(e1.getBounty() + 10);
		p1.setHP(50);
		if (s1.getFloor() < 5) {
			cout << "You are moving to the next floor..." << endl;
			cout << "Current floor: " << s1.getFloor() << endl << endl;
		}

		if (s1.getFloor() == 2) {
			cout << "New powerful weapons have been unlocked in the shop!!" << endl << endl;
			shop.addWeapon(new ShopNode(Sword));
			shop.addWeapon(new ShopNode(Axe));
		}

		else if (s1.getFloor() == 3) {
			cout << "A new powerful weapon has been unlocked in the shop!!" << endl << endl;
			shop.addWeapon(new ShopNode(Gun));
			shop.addWeapon(new ShopNode(Bomb));
		}
	}//while
}//main




void EnemyCombat(enemy& e, Player& p, scoreBoard& s, vector <weapon> &w, list<scoreBoard>& SBList, stack<weapon> &tracker, Shop& shop, stack<enemy> &defeated, queue<string>& sideQuest, stack<int>& combatLog) {
	fstream SBF;
	SBF.open("scoreboard.txt");
	SBF.seekg(0, ios::end);

	cout << "The " << e.getEnemyName() << " attacks you." << endl;
	cout << "You lose " << e.getEnemyDMG() << " HP" << endl << endl;
	p1.modifyHP(-1 * e.getDMG()); 
	combatLog.push(p1.getHP());

	

	if (p.getHP() <= 0) {
		cout << "Your HP is below 0 and you are defeated." << endl;
		cout << "The game is over. Your information will be saved to the player file." << endl << endl;
		f1.Save2File(p1);
		f1.Save2File(s1);
		printSideQuest(sideQuest);
		insertionSort(SBF, s1, SBList);
		cout << endl << "Scoreboard: " << endl;
		for (auto v : SBList) {
			cout << "Player Name : " << v.getName() << setw(30) << "Score: " << v.getScore() << endl;
		}
		QuitGame(SBList, tracker, defeated, shop, e1);
		return;
	}//if
}//EnemyCombat

void PlayerCombat(Player& p, enemy &e, scoreBoard& s, vector <weapon> &weaponList, stack<enemy> &defeated, list<scoreBoard>& SBList, stack<weapon>& tracker, Shop& shop, queue<string>& sideQuest, stack<int>& combatLog) {
	char choice;
	weapon fist("Fist", 10, 99999, 0);
	int size;
	enemyFlag = false;
	p.setDMG(currentWeapon.getDamage());

	while (1) {
		cout << "What would you like to do?" << endl;
		cout << "(A) - Attack" << endl;
		cout << "(S) - Examine Self" << endl;
		cout << "(E) - Examine Enemy" << endl;
		cout << "(C) - Change a weapon" << endl;
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 'A':
			cout << "You cause " << p1.getDMG() << " damage to the enemy" << endl << endl;
			e.modifyEnemyHP(-1 * p1.getDMG());
			combatLog.push(e.getEnemyHP());
			if (quest2_flag == false && s1.getFloor() >= 2) {
				cumulative_damage += p1.getDMG();
			}
			if (quest3_flag == false && s1.getFloor() >= 3) {
				round_count++;
			}

			if (e.getEnemyHP() <= 0) {
				cout << "The enemy is defeated." << endl;
				if (quest3_flag == false && s1.getFloor() >= 3) {
					if (round_count != 1)
						round_count = 0;
				}
				p1.modifyCurrency(e.getBounty());
				if (quest1_flag == false && s1.getFloor() >= 1) {
					cumulative_currency += e.getBounty();
				}
				cout << "you get " << e.getBounty() << " bounty." << endl << endl;
				s.addScore(10 * s.getDiffMod());
				s.setFloor(s.getFloor() + 1);
				addToEnemyStack(e, defeated);
				enemyFlag = true;
			}
			if (currentWeapon.getWName() != "Fist") {
				cout << "Your " << currentWeapon.getWName() << " has been used up." << endl;
				cout << "Your current weapon is switched to Fist" << endl << endl;
				size = weaponList.size();
				for (int i = 0; i < size; i++) {
					if (currentWeapon.getWName() == weaponList[i].getWName()) {
						weaponList.erase(weaponList.begin() + i);
						break;
					}
				}
				currentWeapon = fist;
				p.setDMG(10);
			}
			if (e.getHP() > 0 && enemyFlag == false)
				EnemyCombat(e1, p1, s1, weaponList, SBList, tracker, shop, defeated, sideQuest, combatLog);
			break;

		case 'S':
			cout << "Player info: " << endl;
			p.print();
			PlayerCombat(p, e, s, weaponList, defeated, SBList, tracker, shop, sideQuest, combatLog);
			break;

		case 'E':
			cout << "Enemy Information: " << endl;
			e.printEnemy();
			PlayerCombat(p, e, s, weaponList, defeated, SBList, tracker, shop, sideQuest, combatLog);
			break;

		case 'C':
			if (weaponList.empty() == true) {
				cout << "Your weapon List is empty" << endl << endl;
			}
			else
				ChooseWeapon(weaponList, p);
			break;
		}//switch
		if (enemyFlag == true) {
			break;
		}
	}//while
	
}//PlayerCombat

int PlayerOptions(Player& p, scoreBoard& s, vector <weapon> &weaponList, Shop& shop, stack<weapon> &tracker, fstream& SBF) {
	char choice, option;
	weapon temp;
	string WN;
	p.setDMG(10);
	//SBF.seekg(0, ios::end); 
	cout << "What would you like to do? " << endl;
	cout << "[E]xamine Self" << setw(20) << right << "[C]ontinue" << setw(20) << right << "[B]uy from Shop" 
		 << setw(20)  << right << "[S]coreBoard" << setw(20) << right << "[R]eturn" << endl;
	cin >> choice;
	cout << endl;

	switch (choice) {
	case 'E':
		p.print();
		//PlayerOptions(p, s, weaponList, shop, tracker, SBF);
		cout << endl;
		return 0;
		break;

	case 'C':
		cout << "You start your advanture... " << endl << endl;
		return 1;
		//PlayerCombat(p1, w1, e1, s1);
		break;

	case 'B':
		cout << "Shop:  " << endl;
		cout << "Weapon Name" << setw(20) << right <<  "Damage" << setw(20) << right << "Costs" << endl;
		shop.printAll();
		cout << endl;
		cout << "Your currency amount:  " << p1.getCurrency() << endl;
		cout << "(G) - Go back to Player Option" << endl;
		cout << "(B) - Buy a weapon from the shop" << endl << endl;
		cout << "What would you like to do:    ";
		cin >> option;
		if (option == 'G')
			PlayerOptions(p1, s, weaponList, shop, tracker, SBF);

		else if (option == 'B') {
			cout << "Please enter the name of the weapon youu want to purchase:  ";
			cin >> WN;
			temp = shop.searchWeapon(WN);
			if (p1.getCurrency() >= temp.getCosts()) {
				p1.modifyCurrency(-1 * temp.getCosts());
				weaponList.push_back(temp);
				shop.removeWeapon(temp);
				addToStack(temp, tracker);
				cout << "Purchase successfully!" << endl << endl;
				cout << "Shop Tracker:" << endl;
				cout << "Recently bought weapons:" << endl;
				printStack(tracker);
				cout << endl;
			}
			else
				cout << "Your currency is not enough." << endl << endl;
				}//else if
		else {
			cout << "Invalid input. Return to the player Option page." << endl << endl;
		}
		//PlayerOptions(p1, s, weaponList, shop, tracker, SBF);
		return 0;
		break;

	case 'S':
		cout << "Current Score: " << s.getScore() << endl;
		cout << "Difficulty: " << s.getDiff() << endl;
		cout << "Current Floor: " << s.getFloor() << endl << endl;
		//PlayerOptions(p1, s, weaponList, shop, tracker, SBF);
		cout << endl;
		return 0;
		break;

	case 'R':
		return 2;
		break;

	default:
		cout << "Invalid input" << endl;
	//	PlayerOptions(p1, s, weaponList, shop, tracker, SBF);
		return 0;
		break;
	}//switch

}//PlayerOptions

void ChooseWeapon(vector <weapon> &w1, Player& p) {
	string WN;
	int j, size;
	bool found_flag = false;
	size = weaponList.size();
	cout << "Your weapon list: " << endl;

	cout << "Weapon Name:" << setw(30) << right << "Weapon Damage:" << setw(30) << right << "Uses:" << endl;
	for (j = 0; j < size; j++) {
		cout << weaponList[j].getWName() << setw(40) << right << weaponList[j].getDamage() << setw(30) << right << weaponList[j].getUses() << endl;
	}
	//cout << "Size of weaponList:  " << weaponList2.size() << endl;
	cout << endl;
	cout << "Please enter the name of the weapon to use it:   ";
	cin >> WN;
	cout << endl;
	for (j = 0; j < size; j++) {
		if (weaponList[j].getWName() == WN) {
			currentWeapon = weaponList[j];
			found_flag = true;
			p1.setDMG(currentWeapon.getDamage());
		}
	}//for
	if (found_flag == true)
		cout << "You are currently using " << currentWeapon.getWName() << " as your weapon." << endl << endl;
	else
		cout << "The weapon is not in the list OR the entered weapon name was incorrect" << endl << endl;
}//chooseWeapon



void SBToList(fstream& f, list<scoreBoard>& l) {
	scoreBoard temp;
	string name;
	int score;
	while (!f.eof()) {
		f >> name >> score;
		temp.setName(name);
		temp.setScore(score);
		l.push_back(temp);
	}
}

void searchList(list<scoreBoard>& l) {
	string name;
	bool flag = false;
	cout << "Please enter a name to check the score:  " << endl;
	cin >> name;

	for (auto v : l) {
		if (v.getName() == name) {
			cout << "Player Name: " << v.getName() << setw(30) << "Score: " << v.getScore() << endl;
			flag = true;
		}
		else
			continue;
	}
	if (flag == false)
		cout << "The player does not exist" << endl;
}//searchList


void operator << (list<scoreBoard> l, int i) {
	for (auto v :l) { 
		cout << "Player Name: " << v.getName() << setw(30) << "Score: " << v.getScore() << endl;
	}
}


//void insertionSort(ofstream& f, scoreBoard s, list<scoreBoard> l) {
//	l.push_back(s);
//	l.sort();
//	f.open("scoreboard.txt", std::ofstream::out | std::ofstream::trunc);
//	for (auto v : l) {
//		f << v.getName() << setw(30) << v.getScore() << endl;
//	}
//
//}

void insertionSort(fstream& f, scoreBoard s, list<scoreBoard>& l) {
	int i = 0;
	l.push_back(s);
	l.sort();
	f.open("scoreboard.txt", fstream::out | fstream::trunc);
	f.close();
	f.open("scoreboard.txt");
	f.seekg(0, ios::beg);
	if (f.fail()) {
		cout << "cannot open the file" << endl;
	}

	for (auto v : l) {
		i++;
		if (i == l.size())
			f << v.getName() << '\t' << v.getScore();
		else
			f << v.getName() << '\t' << v.getScore() << endl;
	}
}//insertionSort


void averagedSB(list<scoreBoard>& oldList, list<scoreBoard>& averagedList) {
	list<scoreBoard> sorted;
	bool repeat_check = false;
	int player_count = 0, total_score = 0;

	for (auto v : oldList) {
		for (auto u : sorted) {
			if (v.getName() == u.getName()) {	//chekc if the player's score is averaged
				repeat_check = true;
			}
			else continue;
		}//for

		if (repeat_check == true) {
			repeat_check = false;
			continue;
		}
		else {
			player_count++;
			total_score = v.getScore();
			sorted.push_back(v);

			for (auto l : oldList) {
				if (v.getName() == l.getName()) {
					player_count++;
					total_score += l.getScore();
				}//if
			}//for
			scoreBoard s(v.getName(), total_score / player_count);
			averagedList.push_back(s);
			player_count = 0;
			total_score = 0;
		}//else
	}//for
	averagedList.sort();
}//averagedSB

void addToStack(weapon removed, stack<weapon>& tracker) {
	tracker.push(removed);
}//addToStack

void printStack(stack<weapon> tracker) {
	stack<weapon> temp;
	temp = tracker;
	while (!temp.empty()) {
		cout << temp.top().getWName() << endl;
		temp.pop();
	}
}//PrintStack

void clearStack(stack<weapon>& tracker) {
	while (!tracker.empty()) {
		tracker.pop();
	}
}

void addToEnemyStack(enemy e, stack<enemy>& defeated) {
	defeated.push(e);
}

void clearEnemyStack(stack<enemy>& defeated) {
	while (!defeated.empty()) {
		defeated.pop();
	}
}

void mainMenu(fstream& file, list<scoreBoard>& SBList, list<scoreBoard>& averagedList, stack<weapon>& tracker, stack<enemy>& defeated, Shop& shop, enemy& e1, Player& player, scoreBoard& scoreboard, queue<string>& sideQuest) {
	int i = 0;
	char command;
	cout << "Main Menu:" << endl;
	cout << "(a) ScoreBoard sorted by score" << endl;
	cout << "(b) ScoreBoard sorted by name" << endl;
	cout << "(c) Averaged ScoreBoard" << endl;
	cout << "(d) Search by name" << endl;
	cout << "(e) Enter game" << endl;
	cout << "(q) Quit" << endl << endl;
	
	cout << "Please choose an option:  ";
	cin >> command;
	switch (command) {
	case 'a':
		SBList.sort();
		SBList << i;
		cout << endl;
		mainMenu(file, SBList, averagedList, tracker, defeated, shop, e1, player, scoreboard, sideQuest);
		break;
	case 'b':
		SBList.sort([](scoreBoard lhs, scoreBoard rhs) {return lhs.getName() > rhs.getName(); });
		SBList << i;
		cout << endl;
		mainMenu(file, SBList, averagedList, tracker, defeated, shop, e1, player, scoreboard, sideQuest);
		break;
	case 'c':
		averagedSB(SBList, averagedList);
		averagedList << i;
		cout << endl;
		mainMenu(file, SBList, averagedList, tracker, defeated, shop, e1, player, scoreboard, sideQuest);
		break;
	case 'd':
		searchList(SBList);
		cout << endl;
		mainMenu(file, SBList, averagedList, tracker, defeated, shop, e1, player, scoreboard, sideQuest);
		break;
	case 'e':
		break;
	case 'q':
		cout << "You have quited the game" << endl;
		f1.Save2File(player);
		f1.Save2File(scoreboard);
		printSideQuest(sideQuest);
		insertionSort(file, scoreboard, SBList);
		cout << endl << "Scoreboard: " << endl;
		for (auto v : SBList) {
			cout << "Player Name: " << v.getName() << setw(30) << "Score: " <<  v.getScore() << endl;
		}
		QuitGame(SBList, tracker, defeated, shop, e1);
		break;
	default:
		cout << "Invalid input." << endl << endl;
		mainMenu(file, SBList, averagedList, tracker, defeated, shop, e1, player, scoreboard, sideQuest);
		break;
		
	}
	averagedList.clear();

}


void QuitGame(list<scoreBoard>& SBList, stack<weapon>& tracker, stack<enemy>& defeated, Shop& shop, enemy&e) {
	cout << endl << "You defeated the following enemies: " << endl;
	e << defeated;
	SBList.clear();
	shop.clearShop();
	clearStack(tracker);
	clearEnemyStack(defeated);
	f1.CloseFile();
	exit(1);
}


void printSideQuest(queue<string>& sideQuest) {
	int i, size = sideQuest.size();
	cout << endl << "You have completed the following quest(s) in the game: " << endl;
	for (i = 0; i < size; i++) {
		cout << sideQuest.front() << endl;
		sideQuest.pop();
	}
	cout << endl;
}

void printCombatLog(stack<int>& combatLog, enemy& e) {
	stack<int> temp;
	int i = 0;
	cout << endl <<  "Combat Log:" << endl;
	while (combatLog.empty() == false)
	{
		temp.push(combatLog.top());
		combatLog.pop();
	}

	while (temp.empty() == false)
	{
		int t = temp.top();
		if (i / 2 * 2 == i) {
			cout << "Player HP: " << t << endl;
		}
		else
			cout << e.getEnemyName() << " HP: " << t << endl;
		i++;
		temp.pop();

		// To restore contents of
		// the original stack.
		combatLog.push(t);
	}

	while (combatLog.empty() != true)
		combatLog.pop();
	while (temp.empty() != true)
		temp.pop();
	cout << endl;
}
