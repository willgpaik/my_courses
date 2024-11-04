#include <iostream>
#include "movies.hpp"

using namespace std;

void incrWatched(Movies& movies, string name);
void addMovie(Movies& movies, string name, string rating, int watched);

void incrWatched(Movies& movies, string name)
{
    if (movies.incr(name))
        cout << name << " watch incremented\n";
    else
        cout << name << " not found\n";
}

void addMovie(Movies& movies, string name, string rating, int watched)
{
    if (movies.add(name, rating, watched))
        cout << name << " added\n";
    else
        cout << name << " already exist\n";
}

int main()
{
    Movies myMovies;
    myMovies.disp();

    addMovie(myMovies, "Big", "PG-13", 2);
    addMovie(myMovies, "Star Wars", "PG", 5);
    addMovie(myMovies, "Cinderella", "PG", 7);

    myMovies.disp();

    addMovie(myMovies, "Cinderella", "PG", 7);
    incrWatched(myMovies, "Star Wars");

    myMovies.disp();

    incrWatched(myMovies, "Ice Age");

    return 0;
}
