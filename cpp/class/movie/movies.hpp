#ifndef _HPP_MOVIES_
#define _HPP_MOVIES_

#include <iostream>
#include <string>
#include <vector>
#include "movie.hpp"

using namespace std;

class Movies
{
private:
    vector<Movie> list;

public:
    Movies()
    {
        cout << "(MOVIES) Constructor called\n";
    }

    Movies(const Movies& src)
    {
        cout << "(MOVIES) Copy constructor called\n";
    }

    Movies(Movies&& src) noexcept
    {
        cout << "(MOVIES) Move constructor called\n";
    }

    bool add(string str1, string str2, int val);
    bool incr(string str);
    void disp();

    ~Movies()
    {
        cout << "(MOVIES) Destructor called\n";
    }

};

#endif
