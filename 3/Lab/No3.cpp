//// random.hpp
#ifndef MY_RANDOM_HPP
#define MY_RANDOM_HPP

#include <random>

class Rand_double {
public:
    using seed_type = std::random_device::result_type;

    Rand_double(double low, double high): dist{low,high} {}

    // draw an integer number
    double operator()() { return dist(re); }

    // choose new random engine seed
    void seed(seed_type s) { re.seed(s); }
private:
    std::default_random_engine re;
    std::uniform_real_distribution<double> dist;
};

#include <iomanip>
#include <iostream>
#include <vector>
#include <math.h>

template<typename T_>
inline constexpr
    T_ pi_v{3.141592653589793238462643383279502884L};

inline constexpr double pi = pi_v<double>;

int main()
{
    constexpr double rnd_min = 0.0, rnd_max = 500.0;
    Rand_double rnd{rnd_min, rnd_max};

    std::random_device rd;
    rnd.seed(rd());
    std::cout << std::fixed << std::setprecision(3);
  /*
    double x1 = rnd();
    double y1 = rnd();
    std::cout << "Point #1: (" << x1 << ", " << y1 << ")\n";

    double x2 = rnd();
   double y2 = rnd();
    std::cout << "Point #2: (" << x2 << ", " << y2 << ")";
    std::cout << std::endl;
*/
    std::cout << "<svg width=\"500\" height=\"500\" xmlns=\"http://www.w3.org/2000/svg\">" << std::endl;
    std::cout << "<rect width=\"100%\" height=\"100%\" fill=\"#EEEEEE\" />"<< std::endl;
    std::cout << "<circle cx=\"250\" cy=\"250\" r=\"250\" stroke=\"black\" stroke-width=\"2\" fill=\"none\" />"<< std::endl;
    
    int r =0;
    int N = 5;
    while (r != N) {
      double x = rnd(); double y = rnd();
        double radius = sqrt(x*x +y*y);
    std::cout << "<circle cx=" << std::endl;
    r += 1;
    }
    std::cout<< "</svg>";
    return 0;
}
// end::lab1-3b[]

#endif /* MY_RANDOM_HPP */
