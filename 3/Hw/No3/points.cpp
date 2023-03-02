#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <cmath>
#include <sstream>


using namespace std;

struct Point{
    double x, y;
};

bool is_point_in_unit_circle(const Point& p) 
{
    return hypot(p.x, p.y) <= 1.0;
}

// Generates a random point inside the unit circle using the Mersenne Twister engine
Point generate_random_point_in_unit_circle(mt19937& rng) 
{
    uniform_real_distribution<double> dist{-1.0, 1.0};
    Point p {dist(rng), dist(rng)};
    while (!is_point_in_unit_circle(p)) {
        p = {dist(rng), dist(rng)};
    }
    return p;
}

// Generates an SVG file with circles for the given points
void generate_svg_file(const vector<Point>& points, int width, int height, const string& filename) 
{
    // Construct SVG file contents
    stringstream svg_stream;
    svg_stream << "<svg width=\"" << width << "\" height=\"" << height << "\" xmlns=\"http://www.w3.org/2000/svg\">\n";
    svg_stream << "<rect width=\"100%\" height=\"100%\" fill=\"#EEEEEE\" />\n";
    svg_stream << "<circle cx=\"" << width / 2 << "\" cy=\"" << height / 2 << "\" r=\"" << width / 2 << "\" stroke=\"black\" stroke-width=\"2\" fill=\"none\" />\n";
    for (const auto& p : points) {
        int x = static_cast<int>((p.x + 1) / 2 * width);
        int y = static_cast<int>((1 - p.y) / 2 * height);
        svg_stream << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"10\" fill=\"#FA8072\" />\n";
    }
    svg_stream << "</svg>";

    // Write SVG file to disk
    ofstream svg_file(filename);
    if (svg_file.is_open()) {
        svg_file << svg_stream.str();
        svg_file.close();
        cout << "SVG file written to " << filename << endl;
    } else {
        cerr << "Failed to open file " << filename << endl;
    }
}
