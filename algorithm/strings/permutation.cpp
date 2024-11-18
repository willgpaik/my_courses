// permutation of a string
// i.e. string s = "abc", then "abc", "acb", "bac", "bca", "cab", "cba", total of n!
// this can be described in a tree form so called "state space tree"
// approach is using "back tracking", and "recursion" -> but "brute force"
// lecture 141
#include <iostream>

using namespace std;

void permute1 (char *s, int k)
{
    static int A[100] = {0};
    static char res[100];
    
    if (s[k] == '\0')
    {
        res[k] = '\0';
        cout << res << "\n";
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (A[i] == 0)
        {
            res[k] = s[i];
            A[i] = 1;
            // here, not k++ or ++k, as it will cause 'k' value to be changed
            permute1(s, k+1);
            
            // now convert A[i] back to 0
            A[i] = 0;
        }
    }
}

void permute2 (char *s, int left, int right)
{
    if (left == right)
        cout << s << "\n";

    for (int i = left; i <= right; i++)
    {
        // swap s[left] and s[i]
        char tmp = s[left];
        s[left] = s[i];
        s[i] = tmp;
        
        permute2 (s, left+1, right);

        // swap them back
        s[i] = s[left];
        s[left] = tmp;
    }
}


int main()
{
    char s[] = "abc";
    permute1(s, 0);

    cout << "\n";

    int left = 0;
    int right = 0;

    for (; s[right] != '\0'; right++)
    {}
    permute2(s, 0, right-1);

    return 0;
}
