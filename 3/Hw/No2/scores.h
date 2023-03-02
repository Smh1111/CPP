#ifndef SCORES_H
#define SCORES_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>


using namespace std;

struct Player {
    string name;  
    vector<int> scores;
};
vector<int> splitStringIntoVector(const string& str);
void splitString(const string& str, string& first, string& second);
double getAverage(const Player& a);

bool comparePlayers_byMaxScores(const Player& a, const Player& b);
bool comparePlayers_byMinScores(const Player& a, const Player& b);
bool comparePlayers_byAvgScores(const Player& a, const Player& b);

#endif