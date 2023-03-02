#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include "cmd.h"
using namespace std;


map<string, double> registers;

void set_register(string name, double value) {
    registers[name] = value;
}


double get_register(string name) {
    if (registers.find(name) != registers.end()) {
        return registers[name];
    } else {
        cout << name << ": <N/A>" << endl;
        return 0.0;
    }
}

void add_registers(string name1, string name2) {
    double result = get_register(name1) + get_register(name2);
    set_register(name1, result);
}

void subtract_registers(string name1, string name2) {
    double result = get_register(name1) - get_register(name2);
    set_register(name1, result);
}

void print_registers() {
    for (auto& reg : registers) {
        cout << reg.first << ": " << reg.second << endl;
    }
}
