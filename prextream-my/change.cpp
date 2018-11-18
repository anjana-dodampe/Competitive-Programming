#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(size_t i = 0; i < n; i++)
    {
        int q, k, l;
        cin >> q >> k;
        cout << 
        map<int, int> f;
        map<int, int> d;
        for(size_t j = 0; j < k; j++)
        {
            int from, to;
            cin >> from >> to;
            f[from] = to;
        }
        for(size_t j = 0; j < k; j++)
        {
            int from, to;
            cin >> from >> to;
            d[from] = to;
        }
    }
    

    return 0;
}
