#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iterator>


using namespace std;

void to_upper(char* s)
{
    while (*s)
    {
        if(*s >=97 && *s <=122)
      {
		*s = *s -32;
      }
        //cout << *s << endl;
        cout << s << endl;
        s++;
    }
}


int main()
{
        
        char s[] = "Hello, world";
        cout << sizeof(s) << endl;
        to_upper(s);
        cout << s << endl;
    

        
}