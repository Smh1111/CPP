#include <iostream>
#include <random>
#include <fstream>
using namespace std;

auto check = true;
void check_point_in_unitCircle(double x_value, double y_value)
{
    if (x_value * x_value + y_value * y_value > 1.0)
    {
        check = true;
    }
    else{
        check = false;
    }
}
int main()
{

    int n;
    cout << "How many points: ";
    cin >> n;


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0); // generate random points between -1.0 and 1.0
    std::vector<std::pair<double, double>> points; // a container that holds two data elements
    for (int i = 0; i < n; i++) {
        double x, y;
        do 
        {
            x = dist(gen);
            y = dist(gen);
            check_point_in_unitCircle(x, y);
        } 
        while (check);
        points.push_back({x, y});
    }
    

    std::ofstream outfile("points.svg");
    outfile << "<svg width=\"500\" height=\"500\" xmlns=\"http://www.w3.org/2000/svg\">\n";
    outfile << "<rect width=\"100%\" height=\"100%\" fill=\"#EEEEEE\" />\n";
    outfile << "<circle cx=\"250\" cy=\"250\" r=\"250\" stroke=\"black\" stroke-width=\"2\" fill=\"none\" />\n";
    outfile << "<circle cx=\"250\" cy=\"250\" r=\"10\" fill=\"#00FFFF\" />\n";
    for (const auto& p : points) {
        double x = 250.0 + 250.0 * p.first; // p.first = -0.5, x = 250 + (250 * -0.5) -> left of the center
        double y = 250.0 - 250.0 * p.second; // p.first = 0.2, x = 250 + (250 * 0.2) -> bottom of the center
        outfile << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"2\" fill=\"#FF0000\" />\n"; // (125, 300)
    }
    outfile << "</svg>\n";

    std::cout << "Output written to points.svg\n";
    return 0;
}
