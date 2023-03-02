#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iterator>

using namespace std;
char* rev_dup(const char* s)
{
        int len = strlen(s);
        char* p = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
                p[i] = s[len - i - 1];
        }
        p[len] = '\0';
        return p;
}

int main()
{
        
        char* p = rev_dup("Hello, X");
        cout << p << endl;
        delete[] p;
        
        
}