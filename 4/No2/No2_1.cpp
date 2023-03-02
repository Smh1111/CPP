#include<iostream>
#include<vector>
using namespace std;

vector<string> extract_attrs(vector<string> vec){

    vector<string> temp;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i][0] == '[' && vec[i][1] == '[' && vec[i][vec[i].size()-1] == ']' && vec[i][vec[i].size() - 2] == ']') {
            temp.push_back(vec[i]);
        }
    }
    return temp;
    
    
}
vector<string> extract_non_attrs(vector<string> vec){

    vector<string> temp;
    for (int i = 0; i < vec.size(); i++) {
        if (!(vec[i][0] == '[' && vec[i][1] == '[' && vec[i][vec[i].size()-1] == ']' && vec[i][vec[i].size() - 2] == ']')) {
            temp.push_back(vec[i]);
        }
    }
    return temp;
    
    
}

void print_words(vector<string> vec, ostream& out)
{
for (auto x: vec)
    out << x << ", ";
    out << std::endl;
}


int main()
{
    const vector<string> test_words{
                                "switch", "[[noreturn]]",
                                "if", "[[maybe_unused",
                                "for", "[[fallthrough]]"
                                };
    

    auto attrs = extract_attrs(test_words);

    auto non_attrs = extract_non_attrs(test_words);

    cout << "Test words: ";
    print_words(test_words, cout);
    cout << endl << endl;

    cout << "Attributes: ";
    print_words(attrs, cout);
    cout << endl << endl;

    cout << "Non attributes: ";
    print_words(non_attrs, cout);
    cout << endl << endl;
}
