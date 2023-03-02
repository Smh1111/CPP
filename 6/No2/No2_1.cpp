#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Picture {
    public:
       
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
    Picture p1("Hello, world!");
    std::cout << p1 << "Width: " << p1.width() << ", Height: " << p1.height() << '\n';

    // Create a picture object from a vector of strings
    std::vector<std::string> v = {
        "-------------------------",
        "------SoeMOeHtet----------,",
        "-----------------------",
        "ut labore et dolore magna aliqua."
    };
    Picture p2(v);
    std::cout << p2 << "Width: " << p2.width() << ", Height: " << p2.height() << '\n';

    return 0;
}

