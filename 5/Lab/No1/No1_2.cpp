#include <iostream>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>
using std::cin; using std::cout; using std::endl;
using std::map; using std::string;
using std::sort;
using std::vector;
using namespace std;

// double median(std::vector<double> v);
// int median(std::vector<int> v);

template <class T>
T median(std::vector<T> vec)
{
    if (vec.empty())
        throw domain_error("median of empty vector");

    sort(vec.begin(), vec.end());
    // for (const auto& w: vec) 
    // {
    //     cout << w << " ";
    // }
    const auto size = vec.size();
    const auto mid = size / 2; // vec[1.0]
    return size % 2 == 0? (vec[mid] + vec[mid - 1]) / 2: vec[mid];
}


int main()
{

    vector<double> v = {1.0, 2.0, 5.0, 7.0, 10.0, 20.0};
    cout << endl;
    cout << median(v) << endl;

    try {
        v.clear();
        cout << median(v) << endl;
    }
    catch (const domain_error&) {
        // ...
    }

    v.assign({2, 1, 3, 8, 7});
    cout << median(v) << endl;
    return 0;
}