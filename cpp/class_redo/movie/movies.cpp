#include "movies.hpp"

using namespace std;

bool Movies::add(string str1, string str2, int val)
{
    // check if exist:
    bool added = false;
    for (const Movie &i : list)
    {
        if (i.GetName() == str1)
        {
            return added;
        }
    }

    Movie newMovie {str1, str2, val};
    list.push_back(newMovie);

    added = true;
    return added;
}

bool Movies::incr(string str)
{
    bool exist = false;
    for (Movie &i : list)
    {
        if (i.GetName() == str)
        {
            i.incr();
            exist = true;
            return exist;
        }
    }

    return exist;
}

void Movies::disp()
{
    cout << "==============================\n";
    for (auto i : list)
    {
        i.disp();
    }
    cout << "==============================\n";
}
