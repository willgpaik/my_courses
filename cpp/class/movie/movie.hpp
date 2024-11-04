#ifndef _HPP_MOVIE_
#define _HPP_MOVIE_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie
{
private:
    string name;
    string rating;
    int watched;

public:
    Movie(string str1, string str2, int val)
        : name{str1}, rating{str2}, watched{val}
    {
        cout << "(Movie) Constructor called\n";
    }

    Movie(const Movie& src)
        : Movie{src.name, src.rating, src.watched}
    {
        cout << "(Movie) Copy constructor called\n";
    }

    Movie(Movie&& src) noexcept
        : name{src.name}, rating{src.rating}, watched{src.watched}
    {
        cout << "(Movie) Move constructor called\n";
    }

    ~Movie()
    {
        cout << "(Movie) Destructor called\n";
    }

    void SetName(string str)
    {
        name = str;
    }

    string GetName() const
    {
        return name;
    }

    void SetRating(string str)
    {
        rating = str;
    }

    string GetRating() const
    {
        return rating;
    }

    void SetWatched(int val)
    {
        watched = val;
    }

    int GetWatched() const
    {
        return watched;
    }

    void incr()
    {
        cout << "(Movie) " << name << " incremented\n";
        watched++;
    }

    void disp() const;
};

#endif
