#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iterator>

using namespace std;
// read individual characters until '!' is entered
char* read_text(istream&)
{
        char* p = new char[100];
        int i = 0;
        char ch;
        while (cin.get(ch) && ch != '!')
        {
                p[i] = ch;
                i++;
        }
        p[i] = '\0';
        return p;  
}

int main()
{
        
        cout << "Enter text: ";
        cout << read_text(cin) << endl;
}