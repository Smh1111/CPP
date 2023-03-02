#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include <scores.h>
using namespace std;

// split a string of numbers into a vector of integers.
vector<int> splitStringIntoVector(const string& str) {
    vector<int> result;
    istringstream iss(str);
    int n;
    while (iss >> n) {
          result.push_back(n);
    }
    return result;
}

void splitString(const string& str, string& first, string& second) 
{
    istringstream iss(str);
    getline(iss, first, ' ');
    getline(iss, second);
}
bool comparePlayers_byMaxScores(const Player& a, const Player& b) {
    int maxScoreA = *max_element(a.scores.begin(),a.scores.end());
    int maxScoreB = *max_element(b.scores.begin(), b.scores.end());
    if (maxScoreA != maxScoreB) 
    {
        return maxScoreA > maxScoreB;
    }
    return a.name < b.name;
}

bool comparePlayers_byMinScores(const Player& a, const Player& b) {
    int minScoreA = *min_element(a.scores.begin(),a.scores.end());
    int minScoreB = *min_element(b.scores.begin(), b.scores.end());
    if (minScoreA != minScoreB) 
    {
        return minScoreA > minScoreB;
    }
    return a.name < b.name;
}

double getAverage(const Player& a)
{
    
    int sum = 0;
    for (const auto& score : a.scores) {
      sum += score;
    }
    return (double)sum / a.scores.size();
}
bool comparePlayers_byAvgScores(const Player& a, const Player& b) {
    double avgScoreA = getAverage(a); 
    double avgScoreB = getAverage(b); 
    if (avgScoreA != avgScoreB) 
    {
        return avgScoreA > avgScoreB;
    }
    return a.name < b.name;
}