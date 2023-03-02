#ifndef SCORES_H
#define SCORES_H


#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <cmath>
#include <sstream>

using namespace std;

struct Point {
    double x, y;
};

bool is_point_in_unit_circle(const Point& p);
Point generate_random_point_in_unit_circle(std::mt19937& rng);

void generate_svg_file(const vector<Point>& points, 
                            int width, int height, 
                            const string& filename);



#endif