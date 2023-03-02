#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
class Picture {
private:
    std::vector<std::string> rows;

public:
    
    Picture(const std::string& s) {
        rows.push_back(s);
    }

    Picture(const std::vector<std::string>& v) : rows(v) {}
 
    size_t width() const {
        return std::max_element(rows.begin(), rows.end(),
            [](const std::string& a, const std::string& b) { return a.size() < b.size(); })->size();
    }
 
    size_t height() const {
        return rows.size();
    }
 

    void display(std::ostream& out) const {
        for (const auto& row : rows) {
            out << row << '\n';
        }
    }
 
    void hflip() {
        for (auto& row : rows) {
            if (row.size() < width()) {
                row.append(width() - row.size(), ' ');
            }
           
            std::reverse(row.begin(), row.end());
        }
    }
 

    void vflip() {
        std::reverse(rows.begin(), rows.end());
        for (auto& row : rows) {
            
            if (row.size() < width()) {
                row.append(width() - row.size(), ' ');
            }
        }
    }
 

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
        "############",
        "############",
        "##############",
        "###########"
    };
    Picture p2(v);
    std::cout << p2 <<"Hflip "<< "Width: " << p2.width() << ", Height: " << p2.height() << '\n';
    p2.hflip();
    std::cout << p2;
 
    std::vector<std::string> v1 = {
        "###",
        "###",
        "###",
        "###",
        "###",
        "###",
        "-1",
        "-d",
        "-4",
        "-f",
        "-h",
        "-f"
    };
    Picture p3(v1);
    std::cout << p3 <<"Vflip "<< "Width: " << p3.width() << ", Height: " << p3.height() << '\n';
    p3.vflip();
    std::cout << p3;
 
    return 0;
}

