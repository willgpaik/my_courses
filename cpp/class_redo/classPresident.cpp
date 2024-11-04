#include<iostream>
#include<string>
using namespace std;

class President
{
private:
    President() {}; // private default constructor
    President(const President&); // private copy constructor
    const President& operator=(const President&); // assignment operator

    string name;
public:
    static President& GetInstance()
    {
        // static objects are constructed only once
        static President onlyInstance;
        return onlyInstance;
    }

    string GetName()
    {
        return name;
    }

    void SetName(string Input)
    {
        name = Input;
    }
};

int main()
{
    President& onlyPresident = President::GetInstance();
    onlyPresident.SetName("The Kingking");

//    President second; // can't access default constructor
//    President* third = new President(); // can't access default constructor
//    President fourth = onlyPresident; // can't access copy constructor
//    onlyPresident = President::GetInstance(); // can't access operator=
    
    // following will overwrite the presdient class
    President& fifth = President::GetInstance();
    fifth.SetName("haha hahaha");

    cout << "The name of president: " << onlyPresident.GetName() << "\n";

    return 0;
}
