#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    string name;
    int hp;
    int xp;

public:
    Player()
        : Player {"noname", 100, 0} // argument delegation to 3 args constructor
    {
        cout << "no arg constructor\n";
    }
    
    Player(string str)
        : Player {str, 100, 5} 
    {
        cout << "one arg constructor\n";
    }

    Player(string str, int val1, int val2)
        : name{str}, hp{val1}, xp{val2}
    {
        cout << "three args constructor\n";
    }

    void GetName()
    {
        cout << name << " has " << hp << " health and " << xp << " xp\n";
    }
};

int main()
{
    Player hero{"hero"};
    hero.GetName();

    return 0;
}
