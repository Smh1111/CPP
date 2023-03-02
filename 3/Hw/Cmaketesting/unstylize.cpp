#include "unstylize.h"

std::string unstylize(std::string w)
{
    std::string result = "";
    if (w.size() == 1)
    {
        return w;
    }
    if (w.size() == 2 && w[0] == '*' && w[1] == '*')
    {
        return result;
    }
    else if (w[0] == '*' && w[w.size()-1] == '*')
    {
        for (int i = 1; i <= w.size()-2; i++)
        {
            result += w[i];
        }
        return result;
    }
    else
    {
        return w;
    }
}
