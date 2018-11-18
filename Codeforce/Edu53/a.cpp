#include <bits/stdc++.h>

using namespace std;



int main(int argc, char const *argv[])
{
    int n;
    string s;
    cin >> n >> s;
    for(size_t i = n - 1; i > 0; i--)
    {
        for(size_t j = 0; j < (n - i); j++)
        {
            map<char, int> hash;
            // cout << s.substr(j, i + 1) << endl;
            string sub = s.substr(j, i + 1);
            bool dead = false;

            for(char c: sub)
            {
                hash[c]++;
                if (hash[c] > sub.size()/2) {
                    // cout << "true " << c << " " << n; 
                    dead = true;
                    break;
                }
            }
            
            if (!dead) {
                cout << "YES" << endl << sub << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    
    return 0;
}
