
#include <points.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of points to generate: ";
    cin >> n;

    // Generate random points
    mt19937 rng{random_device{}()};
    vector<Point> points;

    // Requests that the vector capacity be at least enough to contain n elements.
    points.reserve(n);
    
    for (int i = 0; i < n; i++) {
        points.push_back(generate_random_point_in_unit_circle(rng));
    }

    // Write points to SVG file
    string filename = "D:/KMITL University/1st year 2nd sem/OOP/3/Hw/No3/output.svg";
    generate_svg_file(points, 500, 500, filename);

    return 0;
}
