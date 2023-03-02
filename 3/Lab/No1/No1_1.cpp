#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;                  using std::setprecision;
using std::cout;                 using std::string;
using std::endl;                 using std::streamsize;

string tri_pattern(int size)
{
    string result = "";
    for ( int i = 1; i <= size; i++){
      for(int j = 1; j <= i; j++){
        result += "*";
        //std::cout<<"*";
      }
      result += "\n";
      //std::cout<<"\n";
    }
    return result;

}
int main()
{
    auto s = tri_pattern(2);
    cout << s;

    return 0;
}
