#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include <pair.h>
using namespace std;

vector<string> cart_product(const vector<string>& v1, const vector<string>& v2)
{
    vector<string> result;

    for (auto x : v1) {
        for (auto y : v2) {
            result.push_back(x + y);
        }
    }

    return result;
}
vector<pair<string, string>> cartesianProduct(vector<string>& v1, vector<string>& v2) {
    

    vector<pair<string, string>> result;
    for (auto i : v1) {
        for (auto j : v2) {
            result.push_back(make_pair(i, j));
        }
    }
    return result;
}

string Cart_pair(string a, string b) {
    return "(" + a + ", " + b + "), ";
}