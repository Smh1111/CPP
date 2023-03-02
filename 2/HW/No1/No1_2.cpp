#include <iostream>
using namespace std;

void print (string plus, string single, string equals, string spaces, string minus, 
            string war_sp, string mag_sp, string nin_sp, string fig_sp,
            string warrior, string mage, string ninja, string fighter)
{
    // First row
    cout << plus << equals << plus << equals << plus << endl;
    // Second row
    cout << single << spaces << single << spaces  << single << endl;
    // Third row
    cout << "| warrior: " << war_sp << warrior << " |";
    // Fourth row
    cout << " Mage:    " << mag_sp << mage << " |" << endl;
    // Fifth row
    cout << single << spaces << single << spaces  << single << endl;
    // Sixth row
    cout << plus << minus << plus << minus << plus << endl;
    // Seventh row
    cout << single << spaces << single << spaces  << single << endl;
    // Eighth row
    cout << "| Ninja:   " << nin_sp << ninja << " |";
    // Ninth row
    cout << " Fighter: " << fig_sp << fighter << " |" << endl;
    // Tenth row
    cout << single << spaces << single << spaces  << single << endl;
    // 11th row
    cout << plus << equals << plus << equals << plus << endl;
}

int main() {
    string warrior, mage, ninja, fighter;

    cout << "Enter Warrior name: ";
    cin  >> warrior;
    cout << "Enter Mage name: ";
    cin  >> mage;
    cout << "Enter Ninja name: ";
    cin  >> ninja;
    cout << "Enter Fighter name: ";
    cin  >> fighter;

    int warr_len = warrior.length();
    int mag_len = mage.length();
    int ninja_len = ninja.length();
    int fighter_len = fighter.length();
    int highest_len = warr_len;


    if (highest_len < mag_len) 
    {
        highest_len = mag_len;
    }
    else if (highest_len < ninja_len) 
    {
        highest_len = ninja_len;
    }
    else if (highest_len < fighter_len) 
    {
        highest_len = fighter_len;
    }
    else{
        highest_len = warr_len;
    }

    int base_len = ((12 + highest_len) * 2 ) + 1; 

    string equals(((base_len / 2)-1), '=');
    string minus(((base_len / 2)-1), '-');
    string spaces( ((base_len / 2)-1) , ' ');
    string plus   = "+";
    string single = "|";

    int war = highest_len - warr_len;
    int mag = highest_len - mag_len;
    int nin = highest_len - ninja_len;
    int fig = highest_len - fighter_len;

    string war_sp(war, ' '); 
    string mag_sp(mag, ' ');
    string nin_sp(nin, ' ');
    string fig_sp(fig, ' ');
    
    print(plus, single, equals, spaces, minus, war_sp, mag_sp, nin_sp, fig_sp, warrior, mage, ninja, fighter);
    
    return 0;

}