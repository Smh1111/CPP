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
        Nd_vec(const Nd_vec& other) 
        {
            elem = new double[other.sz];
            sz = other.sz;
            for (int i = 0; i < sz; i++)
            {
                elem[i] = other.elem[i];
            }
        };

        // assignment operator
        Nd_vec& operator= (const Nd_vec& rhs)
        {
            cout << "Assignment operator called " << endl;
            return *this;
        }

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
    
    Nd_vec v1(5);
    Nd_vec v2(v1);
    
    v1.print();
    v2.print();

    Nd_vec v3 = v1; 
    v3.print();

    //v3 = v1;
    
    return 0;
}