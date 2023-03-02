#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 using namespace std;

class Picture {
public:
    // Constructor to initialize the picture object with a single string
    Picture(const string& s) {
        rows.push_back(s);
    }

    // Constructor to initialize the picture object with a vector of strings
    Picture(const vector<string>& v) : rows(v) {}
 
    // getting the width of the picture (i.e. the number of columns)
    
    size_t width() const {
        size_t max_width = 0;
        for (const auto& row : rows) {
            if (row.size() > max_width) {
                max_width = row.size();
            }
        }
        return max_width;
    }
 
    // Function to get the height of the picture (i.e. the number of rows)
    size_t height() const {
        return rows.size();
    }
 
    // Function to print the contents of a picture to the output stream
    
    friend ostream& operator<<(ostream& os, const Picture& p) {
        for (const auto& row : p.rows) {
            os << row << '\n';
        }
        return os;
    }
 
    
   

private:
    vector<string> rows;
};
 


int main() {
    Picture p1("This is a test\n1234567890\n");
    Picture p2("This is a test\t222222222222\nThis is next line\n");

    p1.height();
    p1.width();
    p2.height();
    p2.width();

    cout << "Picture 1:" << endl;
    cout << p1 << endl;

    cout << "Picture 2:" << endl;
    cout << p2 << endl;

    
    return 0;
}

