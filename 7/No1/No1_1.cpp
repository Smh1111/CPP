#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
     double coords[5] = {};
     double* p1 = coords;
    //array<double, 3> pt4d;
    //auto arr_it = pt4d.begin();

    vector<double> vec;
    auto vec_it = vec.begin();
    auto vec_end = vec.end();

    cout << "coords: " << sizeof(coords) << endl;
    cout << "p1: " << sizeof(p1) << endl;
    
    // sizeof(coords)  and sizeof(p1) are different because coords is an array and p1 is a pointer.
    // coords is an array of 3 doubles, so it is 24 bytes.
    // p1 is a pointer to a double, so it is 8 bytes.
    // The size of an array is the size of the array elements multiplied by the number of elements.

    cout << "vec: " << sizeof(vec) << endl;
    cout << "vec_it: " << sizeof(vec_it) << endl;

    // number of elements in coords using sizeof
    cout << "number of elements in coords using sizeof: " << sizeof(coords) / sizeof(coords[0]) << endl;
    
    // number of elements in coords through p1
    cout << "number of elements in coords through p1: " << sizeof(coords) / sizeof(*p1) << endl;

    // number of elements in vec using sizeof
    cout << "number of elements in vec using sizeof: " << sizeof(vec) / sizeof(vec[0]) << endl;
    

}