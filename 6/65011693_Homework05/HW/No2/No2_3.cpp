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
 
    // Function to concatenate two pictures horizontally
    Picture hcat(const Picture& other) const {
        vector<string> result;
        auto iter1 = rows.begin();
        auto iter2 = other.rows.begin();
        while (iter1 != rows.end() || iter2 != other.rows.end()) {
            string s;
            if (iter1 != rows.end()) {
                s = *iter1;
                ++iter1;
            }
            s.append(width() - s.size(), ' ');
            if (iter2 != other.rows.end()) {
                s += *iter2;
                ++iter2;
            }
            result.push_back(s);
        }
        return Picture(result);
    }
 
    // Function to concatenate two pictures vertically
    Picture vcat(const Picture& other) const {
        vector<string> result = rows;
        result.insert(result.end(), other.rows.begin(), other.rows.end());
        return Picture(result);
    }
    // resize to adjust the width and height of a picture
    /* The function will expand the picture size when the new width/height is larger and
        crop the picture when the new width/height is smaller. */
    Picture& resize(size_t width, size_t height) {
        if (width < this->width()) {
            for (auto& row : rows) {
                row = row.substr(0, width);
            }
        }
        else if (width > this->width()) {
            for (auto& row : rows) {
                row.append(width - row.size(), '.');
            }
        }
        if (height < this->height()) {
            rows.resize(height);
        }
        else if (height > this->height()) {
            rows.insert(rows.end(), height - rows.size(), string(width, '.'));
        }
        return *this;
    }
  
private:
    vector<string> rows;
};
 


int main() {
    Picture p1("This is a test.1234567890");
    Picture p2("This is a test.222222222222.This is next line");

    p1.height();
    p1.width();
    p2.height();
    p2.width();

    cout << "Picture 1:" << endl;
    cout << p1 << endl;

    cout << "Picture 2:" << endl;
    cout << p2 << endl;

    cout << "Picture 1 and 2 concatenated horizontally:" << endl;
    cout << p1.hcat(p2) << endl;

    cout << "Picture 1 and 2 concatenated vertically:" << endl;
    cout << p1.vcat(p2) << endl;

    cout << "Picture 1 resized to <p1.width>x5:" << endl;
    cout << p1.resize(p1.width(), 5) << endl;

    cout << "Picture 2 resized to 20x5:" << endl;
    cout << p2.resize(20, 5) << endl;

    return 0;
}

