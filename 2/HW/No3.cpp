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
    constexpr double rnd_min = 0.0, rnd_max = 1.0;
    Rand_double rnd{rnd_min, rnd_max};

    std::random_device rd;
    rnd.seed(rd());
    std::cout << std::fixed << std::setprecision(3);

    std::cout << "Please enter N: ";
    int N;
    std::cin>> N;
    
    int count = 0;
    double total_squared_errors = 0.0;
    
    while (count != N){
        double random_num = rnd();
        
        total_squared_errors += (0.5-random_num)*(0.5-random_num);
        
        count++;
    }
    
    double mean_squared_error = total_squared_errors / N;
    std::cout << "MSE is : " << mean_squared_error;
    return 0;
}
// end::lab1-3b[]

#endif /* MY_RANDOM_HPP */


