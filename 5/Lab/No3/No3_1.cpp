#include <iostream>
#include <map>
#include <string>
using namespace std;
template <class W, class S>
S str_join(S splitter,W begin, W end)
{
    
    S result;
    while ( begin != end)
    {
        result += *begin++;
        result += splitter;

    }
    return result;
}

int main()
{
    string s;
    int number;
    map<string, int> counters; // store each word and an associated counter
    // read the input, keeping track of each word and how often we see it
    cout << "Enter: " << endl;

    while (cin >> s >> number)
        counters[s] += number;

        
    // write the words and associated counts
    for (const auto& [key, val]: counters)
        cout << key << "\t" << val << endl;
    return 0;
}
