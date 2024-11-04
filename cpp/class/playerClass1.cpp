#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Player
{
private:
    string name;
    char* initial;
    int hp;
    int xp;
    static int nPlayers;

public:
    Player (string str = "noname", char chr = 'a', int val1 = 100, int val2 = 0)
        : name{str}, hp{val1}, xp{val2}
    {
        initial = new char;
        *initial = chr;
        nPlayers++;
        cout << "constructor called for: " << name << "\n";
    }

    void GetStat() const // guarantee that this object is not changed in this method
    {
        cout << name << " has initial " << initial << " " << hp << " hp and " << xp << " xp\n";
    }

    // deep copy constructor
    Player (const Player& src)
//      : name{src.name}, initial{src.initial}, hp{src.hp}, xp{src.xp}
        : Player{src.name, *src.initial, src.hp, src.xp}
    {
        cout << "deep copy constructor called\n";
    }

    // move constructor
    // noexcept tells the compiler that the method will not throw an exception. Without this the compiler may call the Copy constructor
    Player (Player&& src) noexcept
        : name{src.name}, initial{src.initial}, hp{src.hp}, xp{src.xp}
    {
        nPlayers++;
        src.initial = NULL;
        cout << "move constructor called\n";

    }


    void SetName(string str)
    {
        name = str;
    }

    static int GetNPlayers()
    {
        return nPlayers;
    }

    // destructor
    ~Player()
    {
        nPlayers--;
        if (initial != NULL)
            cout << "destructor called for " << name << "\n";
        else
            cout << "destructor called for " << name << " nullptr\n";
        delete initial;
    }
};

// initialize number of players
int Player::nPlayers = 0;

void dispName(const Player& src) // const Player -> requires const on GetStat method
{
    cout << "player name stat is:\n";
    src.GetStat();
}

void numPlayers()
{
    cout << "current number of players: " << Player::GetNPlayers() << "\n";
}

int main()
{
    cout << "########## Testing regular constructor ##########\n";
    Player hero{"hero"};
    hero.GetStat();

    cout << "\n";
    cout<< "########## Testing copy constructor ##########\n";
    dispName(hero);
    cout << "\n";

    cout << "\n";
    hero.GetStat();

    cout << "\n";
    Player p1;
    p1.GetStat();

    cout << "\n";
    cout << "########### Testing copy constructor ##########\n";
    Player p2{hero};
    p2.GetStat();


    cout << "\n";
    cout << "########### Testing heap ###########\n";
    Player* enemy = new Player;
    enemy->SetName("enemy");
    (*enemy).GetStat();
    delete enemy;


    cout << "\n";
    numPlayers();


    cout << "\n";
    cout << "########## Testing move constructor ##########\n";
    vector<Player> vec;
    vec.push_back(Player{"aa"});
    vec.push_back(Player{"bb"});
    vec.push_back(Player{"cc"});
    vec.back().GetStat();


    cout <<"\n";
    cout << "########## Testing const class ##########\n";
    const Player p3{"p3"};
    dispName(p3);

    cout << "\n";
    numPlayers();

    cout << "\nend of program\n\n";


    return 0;
}
