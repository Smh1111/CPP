#include <iostream>

#include <string>

using std::cin; using std::endl;
using std::cout; using std::string;

int main()

{
    //std::cout << "Please enter Warrior name: ";
    std::string Warrior_name = "ab";

    //std::cin >> Warrior_name;

    //std::cout << "Please enter Ninja name: ";

    std::string Ninja_name = "c";
    //std::cin >> Ninja_name;

    std::string Mage_name = "Rinoa";
    std::string Fighter_name = "Zell";
    

    std::string Warrior    = "Warrior: " + Warrior_name;
    std::string Ninja      = "Ninja:   " + Ninja_name;

    std::string Mage       = "Mage:    ";
    std::string Fighter    = "Fighter: ";

    int greater_warrior_or_ninja;
    int no_spaces;

    std::cout <<  Warrior << std::endl;
    std::cout <<  Ninja << std::endl;

    
    if (Warrior.size() > Ninja.size())
    {
        no_spaces = Warrior.size() - Ninja.size();
        for (int i = 0; i != no_spaces; ++i) 
        {
            Ninja += " ";
        }

        greater_warrior_or_ninja = Warrior.size();
    }
    else
    {
        
        no_spaces = Ninja.size() - Warrior.size();
        for (int i = 0; i != no_spaces; ++i) 
        {
            Warrior += " ";
        }

        greater_warrior_or_ninja = Ninja.size();
    }
    constexpr int pad = 1;
    constexpr int rows = pad * 2 + 3;
    const string::size_type cols = greater_warrior_or_ninja  + pad * 2 + 2;

    cout << endl;
    for (int r = 0; r != rows; ++r) {

      string::size_type c = 0;
      while (c != cols) {
      if (r == pad + 1 && c == pad + 1)
      {
        cout << Warrior;
        c += Warrior.size();
      }
    else
      {
        if (r == 0 && c == 0 || r == 0 && c == greater_warrior_or_ninja + 3 
          || r == rows-1 && c== 0 || r == rows - 1 && c == greater_warrior_or_ninja + 3)

          cout<< "*";

        else if (c == 0 || c == greater_warrior_or_ninja + 3)

          cout << "*";

        else if (r == 0 || r == rows - 1  ||
                c == 0 || c == cols - 1 )

          cout << "*";
        else
          cout << " ";
        ++c;
      }
      }
      cout << endl;
    }
    constexpr int pad1 = 1;
    constexpr int rows1 = pad1 * 2 + 3;
    const string::size_type cols1 = greater_warrior_or_ninja  + pad1 * 2 + 2;

    for (int r = 1; r != rows1; ++r) {

      string::size_type c = 0;
      while (c != cols1) {
      if (r == pad1 + 1 && c == pad1 + 1)
      {
        cout << Ninja;
        c += greater_warrior_or_ninja;

      }
      else
      {

        if (r == rows - 1 && c == 0 || r == rows - 1 && c == greater_warrior_or_ninja + 3)

          cout << "*";


        else if (c == 0 || c == greater_warrior_or_ninja + 3)

          cout << "*";

        else if (r == rows1 - 1  ||

              c == 0 || c == cols1 - 1 )

          cout << "*";

        else

          cout << " ";

        ++c;

      }

      }

      cout << endl;

    }

    return 0;

}

