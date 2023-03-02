#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;                  using std::setprecision;
using std::cout;                 using std::string;
using std::endl;                 using std::streamsize;

string unstylize(string w)
{
    string result = "";
    if (w.size() == 2 && w[0] == '*' && w[1] == '*')
    {
        return result;
    }
    else if (w[0] == '*' && w[w.size()-1] == '*')
    {
        
        for ( int i = 1; i <= w.size()-2; i++)
        {
            result += w[i];
            
            
        }
        return result;
    }
    else
    {
        return w;
    }

}

string stylize(string w)
{
    // Python, c++, ""
    string result = "";
    if (w.size() == 2 && w[0] == '*' && w[1] == '*')
    {
        result += "<strong></strong>";
        return result;
    }
    else if (w[0] == '*' && w[w.size()-1] == '*')
    {
        result += "<strong>";
 
        for ( int i = 1; i <= w.size()-2; i++)
        {
            result += w[i];
            
            
        }
        result += "</strong>";
        return result ;
    }
    else
    {
        return w;
    }

}

int main()
{
    auto words = {"C", "**", "*C++*", "*Java", "*Python*", "Rust*"};
    for (const auto& w: words) 
    {
        std::cout << stylize(w) << std::endl;
    }
}
