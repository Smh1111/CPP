#ifndef SEQUENCE_H
#define SEQUENCE_H // sequence

#include<string>
#include<vector>
using namespace std;
void split_sequence(string line, char delimiter, vector<vector<double>>& doubles);
vector<vector<double>> cartesian_product(
    const vector<double>& seq1, 
    const vector<double>& seq2, 
    const vector<double>& seq3);
#endif