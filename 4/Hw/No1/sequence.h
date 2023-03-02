#ifndef SEQUENCE_H
#define SEQUENCE_H // sequence

#include<string>
#include<vector>
using namespace std;

vector<int> splitStringIntoVector(const string& str);
void splitString(const string& str, string& first, string& second);

void print_seq(const vector<int>& seq);
bool swap_vectors(std::vector<int>& vec1, std::vector<int>& vec2);
vector<int> interleave(const vector<int>& seq1, const vector<int>& seq2, bool flag);
int sop(const vector<int>& seq1, const vector<int>& seq2);
vector<pair<int, int>> cartesianProduct(vector<int>& v1, vector<int>& v2);

#endif