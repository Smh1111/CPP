#ifndef CMD_H
#define CMD_H

#include<string>
#include<vector>
using namespace std;

void set_register(string name, double value);

double get_register(string name);
void add_registers(string name1, string name2);
void subtract_registers(string name1, string name2);
void print_registers();


#endif