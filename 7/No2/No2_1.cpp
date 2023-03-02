#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iterator>

using namespace std;

// write an Nd_vec class which stores an N-dimension of number components.
class Nd_vec
{   
    public:
        // copy constructor
        Nd_vec(const Nd_vec&) = delete;

        // assignment operator
        Nd_vec& operator=(const Nd_vec& rhs) = delete;

        // constructor
        Nd_vec(int s) : elem{new double[s]}, sz{s} { }

        // destructor
        ~Nd_vec()
        {
            delete[] elem;
            cout<<"\n Destructor executed";
        };



    // member function , dimension() for getting the dimension of an Nd_vec object
    int dimension() const { return sz; }



    private:
        /*Data Impl. Type */
        double* elem;
        int sz;

};

int main()
{
    
    Nd_vec v1(10);
    Nd_vec v2(20);
    Nd_vec v3(30);

    cout << v1.dimension() << endl;
    cout << v2.dimension() << endl;
    cout << v3.dimension() << endl;
    return 0;
}