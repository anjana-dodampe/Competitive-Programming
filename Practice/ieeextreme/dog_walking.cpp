#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    
    for(size_t i = 0; i < t; i++)
    {
        int N, K;
        vector<int> s;
        s.resize(N);
        for(size_t j = 0; j < N; j++)
        {
            cin >> s[j];
        }

        sort(s.begin(), s.end());        

        int count = N / K;
        for (size_t e; e < count; e++) {
            
        }

    }
     
    return 0;
}
