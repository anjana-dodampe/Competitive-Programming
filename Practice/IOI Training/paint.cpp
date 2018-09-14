#include <bits/stdc++.h>

using namespace std;

vector<string> ss;

string sp(string s, int k)
{
}

string solve_puzzle(string s, int k, int c[])
{
    int init = c[0];
    for (size_t i = 0; i < k; i++)
    {
        if (s[i] == 'X')
        {
            
        }
        else if (s[i] == '.')
        {

        }
    }
}

int main(int argc, char const *argv[])
{
    string s;
    int k;
    int c[100];
    cin >> s >> k;

    for (size_t i = 0; i < k; i++)
    {
        cin >> c[i];
    }

    solve_puzzle(s, k, c);

    return 0;
}
