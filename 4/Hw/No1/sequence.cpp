#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>


#include <sequence.h>
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
    getline(iss, first, ';');
    getline(iss, second);
}

void print_seq(const vector<int>& seq) {
    for (int i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;
}

// Swap the larger sequence and the smaller sequence by size in a vector of sequences. 
bool swap_vectors(std::vector<int>& vec1, std::vector<int>& vec2)  {

    bool flag = false;
    if (vec1.size() < vec2.size()) {
        vec2.swap(vec1);
        flag = true;
    } 
    return flag;
}

vector<int> interleave(const vector<int>& seq1, const vector<int>& seq2, bool flag) {
    vector<int> result;
    auto seq1_it = seq1.begin();
    auto seq2_it = seq2.begin();
    while (seq1_it != seq1.end() && seq2_it != seq2.end()) {
        result.push_back(*seq1_it++);
        result.push_back(*seq2_it++);
    }
    if (flag)
        while(seq1_it != seq1.end()) {
            result.push_back(*seq1_it++);
    }
    else
        while(seq2_it != seq2.end()) {
            result.push_back(*seq2_it++);
    }
    
    return result;
}

// return the sum of two sequences
int sop(const vector<int>& seq1, const vector<int>& seq2) {
    auto result = 0;
    auto seq1_it = seq1.begin();
    auto seq2_it = seq2.begin();
    
    while (seq1_it != seq1.end() && seq2_it != seq2.end()) {
        result += ((*seq1_it++) * (*seq2_it++));
        
    }
  
    return result;
}
// return the cartesian product of two sequences in a vector of pairs of integers 
vector<pair<int, int>> cartesianProduct(vector<int>& v1, vector<int>& v2) {
    

    vector<pair<int, int>> result;
    for (auto i : v1) {
        for (auto j : v2) {
            result.push_back(make_pair(i, j));
        }
    }
    return result;
}
