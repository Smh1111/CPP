#include <cmath>
#include <seq.h>
#include <fstream>
#include <iostream>
#include <iomanip>

int main() {
    ifstream file("D:/KMITL University/1st year 2nd sem/OOP/4/Hw/No2/data1.txt");
    string line;
    getline(file, line);

    vector<vector<double>> doubles;
    
    auto delimiter = ';';
    split_sequence(line,delimiter, doubles);
    cout << endl;
    
    // Generate the Cartesian product of the sequences
    auto result = cartesian_product(doubles[0], doubles[1], doubles[2]);

    for (const auto& item : result) {
        std::cout << "(";
        for (size_t i = 0; i < item.size(); ++i) {
            std::cout << item[i];
            if (i < item.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }

    
    return 0;
}
