#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>


#include <seq.h>
using namespace std;

void split_sequence(string line, char delimiter, vector<vector<double>>& doubles)

{
    string input = line;
    stringstream input_stream(input);
    string seq; // To store individual words
    while (getline(input_stream, seq, delimiter)) {
        stringstream ss_one_sequence(seq);  // Used for breaking words by whitespace 
        // -> 3, 7, 2,
        // -> 3.5 1.2 2.4
        // -> 4.2 2.7
        vector<double> double_sequence;
        while (ss_one_sequence >> seq) 
        {   
            stringstream each_number(seq); 
            double_sequence.push_back(stod(seq));   
        }
        doubles.push_back(double_sequence);
    }
    cout << endl;
}
// Function to generate the Cartesian product of three sequences
vector<vector<double>> cartesian_product(
    const vector<double>& seq1, const vector<double>& seq2, const vector<double>& seq3)
{
    vector<vector<double>> result;

    for (auto x : seq1) {
        for (auto y : seq2) {
            for (auto z : seq3) {
                result.push_back({x, y, z});
            }
        }
    }

    return result;
}