#ifndef SEQUENCE_H
#define SEQUENCE_H // sequence

#include<string>
#include<vector>
using namespace std;


vector<string> cart_product(const vector<string>& v1, const vector<string>& v2);
vector<pair<string, string>> cartesianProduct(vector<string>& v1, vector<string>& v2);
string Cart_pair(string a, string b);

#endif