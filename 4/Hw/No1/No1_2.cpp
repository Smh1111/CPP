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
            string first, second;
            splitString(line, first, second);
            
            seq1 = splitStringIntoVector(first);
            seq2 = splitStringIntoVector(second);    
        }
    }
    file.close();
    bool flag = swap_vectors(seq1, seq2);
    cout << "seq1 is: ";    print_seq(seq1);
    cout << "seq2 is: ";    print_seq(seq2);

    cout << "Sum of product: " << sop(seq1, seq2) << endl;

    return 0;
}
