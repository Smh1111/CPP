
#include <scores.h>
using namespace std;


int main() {
    Player record;
    vector<Player> players;
    string::size_type maxlen = 0;

    ifstream file("D:/KMITL University/1st year 2nd sem/OOP/3/Hw/No2/names.txt");
    if (file.is_open())
    {
    	string line;
    	while (getline(file, line))
        {
        	// note that the newline character is not included
            // in the getline() function	
            string first, second;
            splitString(line, first, second);
            
            vector<int> numbers = splitStringIntoVector(second);
            players.push_back({first, numbers});
        }
    }
    int maxNameLength = 0;
    for (const auto& player : players) 
    {
        if (maxNameLength < (int)player.name.length()) 
        {
            maxNameLength = (int)player.name.length();
        }
    }
    sort(players.begin(), players.end(), comparePlayers_byAvgScores);

    int rank = 1;
    for (const auto& player : players) 
    {
        try 
        {
            streamsize prec = cout.precision();

            double avgScore =  getAverage(player);
            if (avgScore != (int)avgScore) 
            {
                cout << rank << ". " << left << setw(maxNameLength + 1) << player.name; 
                cout << fixed << setprecision(2) << avgScore;
                
            }
            else
            {
                cout << rank << ". " << left << setw(maxNameLength + 1) << player.name; 
                cout << (int)avgScore;
            }
        }
        catch (const domain_error& e) 
        {
            cout << e.what();
        }
        cout << endl;
        ++rank;
    }
    return 0;
}