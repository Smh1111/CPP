bool is_prime(int n)
{
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

// check through all numbers of the form i = 6k - 1 and i = 6k + 1
    for (int i = 5; i * i <= n; i+= 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false; // n is divisible by i or i + 2
    }
    return true; // no divisor within [5, n) found
}

#include <iostream>
int main()
{
using std::cout;
using std::cin;
using std::endl;
cout << "Enter the upper limit: ";
int n;
cin >> n;
if (n >= 2) {
    cout << 2 << endl;
}
for (int i = 3; i <= n; i ++) {
if (is_prime(i))
cout << i << endl;
}
return 0;
}