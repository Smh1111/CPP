#include <iostream>
#include <fstream>
#include <sequence.h>
using namespace std;

int main() {
    ifstream file("D:/KMITL University/1st year 2nd sem/OOP/4/Hw/No1/data2.txt");
    
    vector<int> seq1, seq2;

    if (file.is_open())
    {
    	string line;
        

    	while (getline(file, line))
        {
        	// note that the newline character is not included
            // in the getline() function	
            string first, second;
            splitString(line, first, second);
            
            seq1 = splitStringIntoVector(first);
            seq2 = splitStringIntoVector(second);
            
        }
    }
    file.close();
    vector<pair<int, int>> cp = cartesianProduct(seq1, seq2);
    for (auto p : cp) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    return 0;
}
