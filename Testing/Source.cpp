#include <iostream>
#include <string>
#include "json.hpp"
#include <fstream>
#include <Windows.h>
using namespace std;
using json = nlohmann::json;

string playerFolder = "", playerName = "";
int adminLevel = 0;

void loadConfig() {
	ifstream ifs("config.json");
	json j;
	ifs >> j;
	ifs.close();
	if (ifs.is_open()) {
		cout << "config.json Already Opened By UNKNOW Application!" << endl;
		return;
	}
	playerFolder = j["playerFolder"].get<string>();
}

int main() {
	while (true)
	{
		loadConfig();
		cout << "Admin Level Changer With C++" << endl;
		cout << "Made By TheX#2933" << endl;
		cout << "Enter Player Name: ";
		cin >> playerName;
		cout << "Enter New Admin Level: ";
		cin >> adminLevel;
		cout << "Player Folder: " << playerFolder << "\nPlayer Name: " << playerName << endl;

		ifstream ifs(playerFolder + "/" + playerName + ".json");
		json j;
		ifs >> j;
		ifs.close();
		if (ifs.is_open()) {
			cout << playerFolder << "/" << playerName << ".json Already Opened By UNKNOW Application!";
			break;
		}
		j["adminLevel"] = adminLevel;
		ofstream ofs(playerFolder + "/" + playerName + ".json");
		ofs << j << endl;
		ofs.close();
		cout << "Successfully Change Admin Level " << playerName << " To " << adminLevel << endl;
		Sleep(5000);
		system("cls");
	}
	return 0;
}