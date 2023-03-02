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

    // print() for printing the elements of an Nd_vec object
    void print() const
    {
        for (int i = 0; i < sz; i++)
        {
            elem [i] = i;
            cout << elem[i] << " ";
        }
        cout << endl;
    }

    private:
        /*Data Impl. Type */
        double* elem;
        int sz;

};

int main()
{
    
    Nd_vec v1(10);
    
    v1.print();
    return 0;
}