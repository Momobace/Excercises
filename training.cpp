//
// Created by Momchil Tsanov on 11.11.23.
//
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void fillTeamPlayers(int sizeOfTeam, int* team);
void deleteIfPlayerExist(int currentNum, int sizeOfTeam, int* team, int& playersInTeam);


int main() {
    const int MAX_TEAM_SIZE = 12;

    string teamName, teamName2;
    int teamNum1[12], teamNum2[12];

    int redFlags;

    getline(cin, teamName);
    fillTeamPlayers(MAX_TEAM_SIZE, teamNum1);


    getline(cin, teamName2);
    fillTeamPlayers(MAX_TEAM_SIZE, teamNum2);

    cin >> redFlags;
    cin.ignore();

    string currentTeam;
    int currentNum;
    int playersInTeam1 = 12;
    int playersInTeam2 = 12;

    for (int i = 0; i < redFlags; i++) {
        getline(cin, currentTeam);
        cin >> currentNum;
        cin.ignore();

        if (currentTeam == teamName) {
            deleteIfPlayerExist(currentNum, MAX_TEAM_SIZE, teamNum1, playersInTeam1);
        } else {
            deleteIfPlayerExist(currentNum, MAX_TEAM_SIZE, teamNum2, playersInTeam2);
        }

        if (playersInTeam1 < 8 || playersInTeam2 < 8) {
            cout << "Game was terminated" << endl;
            break;
        }
    }
        cout << "Team " << teamName << " " << playersInTeam1 << endl
        << "Team " << teamName2 << " " << playersInTeam2 << endl;

    return 0;
}

void fillTeamPlayers(int sizeOfTeam, int* team) {

    int currentNum;

    for (int i = 0; i < sizeOfTeam; i++) {
        cin >> currentNum;
        team[i] = currentNum;
    }
    cin.ignore();
}

void deleteIfPlayerExist(int currentNum, int sizeOfTeam, int* team, int& playersInTeam) {

    for (int i = 0; i < sizeOfTeam; i++) {
        if (currentNum == team[i]) {
            team[i] = -1;
            playersInTeam--;
            break;
        }

    }
}







