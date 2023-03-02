#include<iostream>
#include<vector>
#include<list>
using namespace std;

template <class T> T remove_negative(T sth)
{
    T v;
    for (const auto& w: sth) 
    {   
        if (w>0){
            v.push_back(w);
        }
        //cout << w << " ";
    }
    return v;
}
int main(){
    vector<double> vec1{0.8,-5.1,1.6,-6.5,10.5};
    auto vec2 = remove_negative(vec1);
    for (const auto& i: vec2) 
    {
        cout << i << " ";
    }
    cout << endl;
    list<double> li1(vec1.begin(),vec1.end());
    auto li2 = remove_negative(li1);
    for (const auto& i: li2) 
    {
        cout << i << " ";
    }

}