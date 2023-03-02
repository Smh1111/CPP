#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <pair.h>

using namespace std;


int main() {
    ifstream file("D:/KMITL University/1st year 2nd sem/OOP/4/Hw/No3/data1.txt");
    string line;
    getline(file, line);

    stringstream input_stream(line);

    string words;
    vector<string> words_withEnclosing;
    vector<string> words_withoutEnclosing;

    while(getline(input_stream, words, ' '))
    {

        if (words[0] == '*' && words[words.size() - 1] == '*')
        {
            words_withEnclosing.push_back(words);
        }
        else
        {
            words_withoutEnclosing.push_back(words);
        }
    }

    auto result = cartesianProduct(words_withEnclosing, words_withoutEnclosing);
    string p;
    for (auto item : result) {
        p += Cart_pair(item.first, item.second);
        
    }
    p.resize(p.size() - 2);
    cout << p << endl;
    
    return 0;
}
