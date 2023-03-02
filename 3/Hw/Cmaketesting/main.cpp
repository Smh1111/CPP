#include <iostream>
#include <vector>
#include <string>
#include "unstylize.h"

using namespace std;

int main() 
{
    char arr[200];
    cout << "Enter words: ";
    cin.getline(arr, 200); 
    char separator = ' ';
    int i = 0;
    int space_total = 1;
    string s; 
    vector<string> result;

    while (arr[i] != '\0') 
    {
        if (arr[i] != separator) 
        {
            s += arr[i]; 
        } 
        else 
        {
            result.insert(result.begin(), s);
            s.clear();
        }
        i++;
    }
    result.insert(result.begin(), s);

    for (const auto& w: result) 
    {
        cout << unstylize(w) << " ";
    }
    cout << endl;
    return 0;
}
