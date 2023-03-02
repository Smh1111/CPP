#include <iostream>
#include <fstream>
#include <sequence.h>
using namespace std;

int main() {
    ifstream file("D:/KMITL University/1st year 2nd sem/OOP/4/Hw/No1/data1.txt");
    
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
    // Swap the sequences by size

    bool flag = swap_vectors(seq1, seq2);
    // Interleave the sequences
    cout << "seq1 is: ";    print_seq(seq1);
    cout << "seq2 is: ";    print_seq(seq2);
    cout << "flag is: " << flag << endl;
    
    vector<int> interleaved;
    if (flag)
        interleaved = interleave(seq1, seq2, flag);
    else
        interleaved = interleave(seq1, seq2, flag);

    cout << "interleaved is: ";    print_seq(interleaved);
    return 0;
}
