// count number of words in the sentence
#include <iostream>

using namespace std;

void cntVowelAndConsonent(char *a)
{
    int vCnt = 0;
    int cCnt = 0;
    cout << "\"";
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || \
                a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
            vCnt++;
        else if ((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122))
            cCnt++;
        cout << a[i];
    }

    cout << "\" has " << vCnt << " vowels and " << cCnt << " consonents\n";
}

void cntWord(char *a)
{
    int word = 1;
    cout << "\"";
    for (int i = 0; a[i] != '\0'; i++)
    {
        if ((a[i] == ' ' && a[i-1] != ' ') || (a[i] == '\0'))
            word++;
        cout << a[i];
    }

    cout << "\" has " << word << " words\n";
}



int main()
{
    char a[] = "How are you";

    cntVowelAndConsonent(a);

    cntWord(a);

    return 0;
}
