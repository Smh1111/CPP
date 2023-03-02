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
    
    for (const auto& double_sequence : doubles) {
        auto sum = 0.0;
        for (const auto& d : double_sequence) {
            cout << d << " ";
            sum += d;

        }
        cout << endl << "sum: " << sum << endl;
        
        cout << "avg: " << setprecision(3) << floor(100 * (sum / double_sequence.size())) / 100 << endl;
        cout << endl;
    }

    
    return 0;
}
