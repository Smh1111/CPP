#include <iostream>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>

using std::map; using std::string;
using std::sort;
using std::vector;
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

    auto words = vector<string>{"C", "Rust", "C++", "Python"};
    auto str1 = str_join(string(", "), words.begin(), words.end());
    auto words2 = list<string>(words.rbegin(), words.rend());
    auto str2 = str_join(string(", "), words2.begin(), words2.end());

    cout << str1 << endl;
    cout << str2 << endl;
    

    return 0;
}