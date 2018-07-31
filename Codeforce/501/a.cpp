#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int a[100];
    int n, m;
    cin >> n >> m;
    fill_n(a, m, 1);
    
    for(size_t i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        
        for(size_t j = l - 1; j <=  r - 1; j++)
        {
            a[j] = 0;
        }
        
    }
    int count =  0;
    for(size_t i = 0; i < m; i++)
    {
        if (a[i] == 1) {
            count++; 
        }
    }
    cout << count << '\n';
    for(size_t i = 0; i < m; i++)
    {
        
        if (a[i] == 1) {
            cout << i + 1 << " ";
        }
        
    }

    return 0;
}
