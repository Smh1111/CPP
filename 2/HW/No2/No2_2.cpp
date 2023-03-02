#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double temp = 0;
    cout<< "Fahr    Celsius" << endl;
    for (double f= 0.0; f <= 300.0 ; f+= 40 )
    {
        temp = (5.0/9.0) * (f-32.0);
        if (temp > 100)
        {
          cout<< setw(3) << f << setw(12) << setprecision(4) << temp << endl;
        }
        else
        {
          cout<< setw(3) << f << setw(12) << setprecision(3) << temp << endl;
        }
  }
  return 0;
}
