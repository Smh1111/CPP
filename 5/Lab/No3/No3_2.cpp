#include <iostream>
#include <map>
#include <string>
using namespace std;
template <class W, class S>

int main()
{
    string s;
    string number;
    map<string, string> counters; // store each word and an associated counter
    // read the input, keeping track of each word and how often we see it
    cout << "Enter: " << endl;

    while (cin >> s >> number)
        counters[s] += number + ", ";

        
    // write the words and associated counts
    for (const auto& [key, val]: counters)
        cout << key << "\t" << val << endl;
    return 0;
}
