#include <iostream>
using namespace std;

void print (string star, string stars, string spaces, 
            string war_sp, string mag_sp, string nin_sp, string fig_sp,
            string warrior, string mage, string ninja, string fighter)
{
    // First row
    cout << stars << endl;
    // Second row
    cout << star << spaces << star << spaces  << star << endl;
    // Third row
    cout << "* Warrior: " << war_sp << warrior << " *";
    // Fourth row
    cout << " Mage:    " << mag_sp << mage << " *" << endl;
    // Fifth row
    cout << star << spaces << star << spaces  << star << endl;
    // Sixth row
    cout << stars << endl;
    // Seventh row
    cout << star << spaces << star << spaces  << star << endl;
    // Eighth row
    cout << "* Ninja:   " << nin_sp << ninja << " *";
    // Ninth row
    cout << " Fighter: " << fig_sp << fighter << " *" << endl;
    // Tenth row
    cout << star << spaces << star << spaces  << star << endl;
    // 11th row
    cout << stars << endl;
}
int main() 
{
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

    int stars_len = ((12 + highest_len) * 2 ) + 1; 
    string stars(stars_len, '*');
    string spaces( ((stars_len / 2)-1) , ' ');

    int war = highest_len - warr_len;
    int mag = highest_len - mag_len;
    int nin = highest_len - ninja_len;
    int fig = highest_len - fighter_len;
    string star = "*";

    string war_sp(war, ' '); 
    string mag_sp(mag, ' ');
    string nin_sp(nin, ' ');
    string fig_sp(fig, ' ');
    
    print(star, stars, spaces, war_sp, mag_sp, nin_sp, fig_sp, warrior, mage, ninja, fighter);

    
    return 0;
}