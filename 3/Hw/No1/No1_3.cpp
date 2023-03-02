#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <unstylize.h>
using namespace std;

int main() 
{
    // C *C++* Rust* *Python* * *Java
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
            //result.insert(result.begin(), s);
            result.push_back(unstylize(s));
            s.clear();
        }
        i++;

    }
    //result.insert(result.begin(), s);

    result.push_back(unstylize(s));

    sort(result.begin(),result.end());//Sorting the vector
	
	cout<<"After sorting vector : ";
	for(auto i = result.begin(); i < result.end(); i++)
	{
		cout<<" "<<*i;
	}
    cout << endl;
    return 0;
}