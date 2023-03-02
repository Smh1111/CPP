#include<iostream>
#include<vector>
#include<list>
using namespace std;
template <class T> bool all_zeros(T begin, T end)
{
    if (begin == end || *begin == 0)
        return 0;
    else
        return 1;
    return all_zeros(++begin, end);
}
int main(){
    vector<int> vec1{1,0,2,3};
    vector<int> vec2(10);
    bool z1 = all_zeros(vec1.begin(),vec1.end());
    bool z2 = all_zeros(vec2.begin(),vec2.end());

    list<int> li1(vec1.rbegin(), vec1.rend());
    list<int> li2(10);
    bool zz1 = all_zeros(li1.begin(), li1.end());
    bool zz2 = all_zeros(li2.begin(), li2.end());
    
    cout<<"z1: "<<z1<<endl;
    cout<<"z2: "<<z2<<endl;

    cout<<"z11: "<<z1<<endl;
    cout<<"z22: "<<z2<<endl;
    return 0;
}