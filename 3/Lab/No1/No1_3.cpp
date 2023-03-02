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


    for ( int i = 1; i < size; i++){
      for(int j = 0; j < size - i; j++){
        result += " ";
        //std::cout<<" ";
      }
      for(int k=1; k<=i;k++ ){
        result += "*";
        //std::cout<<"*";
      }
      result += "\n";
      //std::cout<<"\n";
    }
  
    for ( int i = 1; i <= size; i++){
      
      for(int j = 1; j < i; j++){
        result += " ";
        //std::cout<<" ";
      }
      for(int k=size; k>=i;k--){
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
    auto s = tri_pattern(5);
    cout << s;

    return 0;
}
