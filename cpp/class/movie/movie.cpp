#include "movie.hpp"

using namespace std;

void Movie::disp() const
{
    cout << name << ", " << rating << ", " << watched << "\n";
}
