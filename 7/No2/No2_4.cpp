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
        Nd_vec(int s) : elem{new double[s]}, sz{s} {
            for (int i = 0; i < sz; i++)
            {
                elem[i] = 10;
            }
         }

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
       
        if (sz > 0){
             cout << "Printing elements: " << endl;
            for (int i = 0; i < sz; i++)
            {
                
                cout << elem[i] << " ";
            }
        }
        
        else
        {
            cout << "No elements to print" << endl;
        }
        cout << endl;
    }

    // clear function to deallocates all the free memory used by Nd_vec object
    // After calling vec.clear(), its dimension should be 0 and the object contains no data for its contents.
    void clear()
    {
        delete[] elem;
        sz = 0;
    }

    void print_size() const
    {
        cout << "Size: " << sz << endl;
    }

    // add(v1, v2) for creating a new Nd_vec object which is the sum of two Nd_vec objects v1 and v2.
    void add(const Nd_vec& v1, const Nd_vec& v2)
    {
        if (v1.sz == v2.sz)
        {
            for (int i = 0; i < v1.sz; i++)
            {
                elem[i] = v1.elem[i] + v2.elem[i];
            }
        }
    }

    void subtract(const Nd_vec& v1, const Nd_vec& v2)
    {
        if (v1.sz == v2.sz)
        {
            for (int i = 0; i < v1.sz; i++)
            {
                elem[i] = v1.elem[i] - v2.elem[i];
            }
        }
    }

    // creating a new Nd_vec object by scaling a vector v by x
    void scale(const Nd_vec& v, double x)
    {
        for (int i = 0; i < v.sz; i++)
        {
            elem[i] = v.elem[i] * x;
        }
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
    v1.print_size();

    


    // adding
    cout << endl << "Adding" << endl;
    Nd_vec v3(5);
    v3.add(v1, v2);

    v3.print();

    // subtracting
    cout << endl << "Subtracting" << endl;
    Nd_vec v4(5);
    v4.subtract(v1, v2);
    v4.print();

    // scaling
    cout << endl << "Scaling" << endl;
    Nd_vec v5(5);
    v5.scale(v1, 4);
    v5.print();

    return 0;
}