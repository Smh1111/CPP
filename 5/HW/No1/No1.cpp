#include <cmd.h>
#include <iostream>

using namespace std;


int main() {
    string command, name1, name2;
    double value;

    while (true) {
        cout << "cmd: ";
        cin >> command;

        if (command == "set") {
            cin >> name1 >> value;
            set_register(name1, value);
        } else if (command == "get") {
            cin >> name1;
            if (get_register(name1) != 0.0)
                cout << name1 << ": " << get_register(name1) << endl;
            
        } else if (command == "add") {
            cin >> name1 >> name2;
            add_registers(name1, name2);
        } else if (command == "subtract") {
            cin >> name1 >> name2;
            subtract_registers(name1, name2);
        } else if (command == "print") {
            print_registers();
        } else if (command == "exit") {
            break;
        } else {
            cout << "Invalid command. Try again." << endl;
        }
    }

    return 0;
}
