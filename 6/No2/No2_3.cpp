#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
class Picture {
public:
    // Constructor to initialize the picture object with a single string
    Picture(const std::string& s) {
        rows.push_back(s);
    }

    // Constructor to initialize the picture object with a vector of strings
    Picture(const std::vector<std::string>& v) : rows(v) {}
 
    // Function to get the width of the picture (i.e. the length of the longest row)
    size_t width() const {
        return std::max_element(rows.begin(), rows.end(),
            [](const std::string& a, const std::string& b) { return a.size() < b.size(); })->size();
    }
 
    // Function to get the height of the picture (i.e. the number of rows)
    size_t height() const {
        return rows.size();
    }
 
    // Function to display the picture
    void display(std::ostream& out) const {
        for (const auto& row : rows) {
            out << row << '\n';
        }
    }
 
    // Function to flip the contents of the picture horizontally
    void hflip() {
        for (auto& row : rows) {
            // If the row is shorter than the width, fill blank characters on the right to fit the width
            if (row.size() < width()) {
                row.append(width() - row.size(), ' ');
            }
            // Flip the row
            std::reverse(row.begin(), row.end());
        }
    }
 
    // Function to flip the contents of the picture vertically
    void vflip() {
        std::reverse(rows.begin(), rows.end());
        for (auto& row : rows) {
            // If the row is shorter than the width, fill blank characters on the right to fit the width
            if (row.size() < width()) {
                row.append(width() - row.size(), ' ');
            }
        }
    }
 
    // Function to concatenate two pictures horizontally
    Picture hcat(const Picture& other) const {
        std::vector<std::string> result;
        auto iter1 = rows.begin();
        auto iter2 = other.rows.begin();
        while (iter1 != rows.end() || iter2 != other.rows.end()) {
            std::string s;
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
        std::vector<std::string> result = rows;
        result.insert(result.end(), other.rows.begin(), other.rows.end());
        return Picture(result);
    }
 
private:
    std::vector<std::string> rows;
};
 
// Overload the output operator to display the picture object
std::ostream& operator<<(std::ostream& out, const Picture& p) {
    p.display(out);
    return out;
}
int main() {
    // Create a picture object from a single string
    //Picture p1("Hello, world!");
    //std::cout << p1 << "Width: " << p1.width() << ", Height: " << p1.height() << '\n';
    //p1.hflip();
    //std::cout << p1;
 
    // Create a picture object from a vector of strings
    std::vector<std::string> v = {
        "eeeeeeeeee",
        "dddddddddd#",
        "aaaaaaaaaaaa",
    };
    Picture p2(v);
    std::cout << p2 <<"Hflip "<< "Width: " << p2.width() << ", Height: " << p2.height() << '\n';
    p2.hflip();
    std::cout << p2;
 
    std::vector<std::string> v1 = {
        "345",
        "###",
        "123",
        
    };
    Picture p3(v1);
    std::cout << p3 <<"Vflip "<< "Width: " << p3.width() << ", Height: " << p3.height() << '\n';
    p3.vflip();
    std::cout << p3;
 
    Picture p5 = p2.hcat(p3);
    std::cout << p5;
    //p2.vcat(p3);

    return 0;
}

