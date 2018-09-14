#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        int n, k, c = 0;
        cin >> n >> k;
        int s[10000];
        for (size_t j = 0; j < n; j++)
        {
            cin >> s[j];
            int mul = 1;
            
            int q = j;
            while(mul < k && q >= 0){
                mul *= s[q];
                
                if (mul == k) {
                    c++;
                }
                q--;
            }
        }
        cout << c << "\n";
    }

    return 0;
}
