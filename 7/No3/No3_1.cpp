#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iterator>

using namespace std;

// write a Picture class which stores a collection of rows of a text string for its contents
// The longest row determines the width of the Picture and the number of rows determines the height of the Picture.
class Picture
{
    public:
        // constructor
        Picture(int r, int c) : row{new char*[r]}, row_size{r}, col_size{c}
        {
            for (int i = 0; i < row_size; i++)
            {
                row[i] = new char[col_size];
                for (int j = 0; j < col_size; j++)
                {
                    row[i][j] = ' ';
                }
            }
        };

        // destructor
        ~Picture()
        {
            delete[] row;
            cout<<"\n Destructor executed";
        };
        
        // set_row() for setting the number of rows of a Picture object
        void set_row(int r)
        {
            row = new char*[r];
            row_size = r;
        }

        // set_col() for setting the number of columns of a Picture object
        void set_col(int c)
        {
            col_size = c;
        }

        // assignment constructor
        Picture& operator= (const Picture& rhs)
        {
            cout << "Assignment operator called " << endl;
            return *this;
        }

        // copy constructor
        Picture(const Picture& other) 
        {
            row = new char*[other.row_size];
            row_size = other.row_size;
            col_size = other.col_size;
            for (int i = 0; i < row_size; i++)
            {
                row[i] = new char[col_size];
                for (int j = 0; j < col_size; j++)
                {
                    row[i][j] = other.row[i][j];
                }
            }
        };

        

        // get_row() for getting the number of rows of a Picture object
        int get_row() const { return row_size; }

        // get_col() for getting the number of columns of a Picture object
        int get_col() const { return col_size; }

        // print() for printing the contents of a Picture object
        void print() const
        {
            for (int i = 0; i < row_size; i++)
            {
                for (int j = 0; j < col_size; j++)
                {
                    cout << row[i][j];
                }
                cout << endl;
            }
        }

        // clear() for clearing the contents of a Picture object
        void clear()
        {
            for (int i = 0; i < row_size; i++)
            {
                for (int j = 0; j < col_size; j++)
                {
                    row[i][j] = ' ';
                }
            }
        }

        // hcat for concatenating two Picture objects horizontally
        Picture hcat(const Picture& rhs)
        {
            Picture p(row_size, col_size + rhs.col_size);
            p.set_col(col_size + rhs.col_size);
            for (int i = 0; i < row_size; i++)
            {
                for (int j = 0; j < col_size; j++)
                {
                    p.row[i][j] = row[i][j];
                }
                for (int j = col_size; j < col_size + rhs.col_size; j++)
                {
                    p.row[i][j] = rhs.row[i][j - col_size];
                }
            }
            return p;
        }

        // vcat for concatenating two Picture objects vertically
        Picture vcat(const Picture& rhs)
        {
            
            Picture p(row_size + rhs.row_size, col_size);
            for (int i = 0; i < row_size; i++)
            {
                for (int j = 0; j < col_size; j++)
                {
                    p.row[i][j] = row[i][j];
                }
            }
            for (int i = row_size; i < row_size + rhs.row_size; i++)
            {
                for (int j = 0; j < col_size; j++)
                {
                    p.row[i][j] = rhs.row[i - row_size][j];
                }
            }
            return p;
        }
        
    private:
        char** row;
        int row_size;
        int col_size;

};

int main()
{
    Picture p1(3, 4);
    
    p1.print();

    return 0;
}