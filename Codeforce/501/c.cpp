#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> a;
    
    for(size_t i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        sum += x;
        int temp =  x - y;
        a.push_back(temp);
        // cout << a[i] << '\n';
    }
    
    sort(a.begin(), a.end());
    int count = 0;
    for(size_t i = n; i > 0 ; i--)
    {
        cout << a[i-1] << " " << sum << "\n";
        if (sum > m) {
            count++;
            sum -= a[i-1];
        } 
        else
        {
            break;
        }        
    }
    
    cout << sum << "\n";
    if (sum > m) {
        cout << -1;
        return 0;
    }

    cout << count;
    
    return 0;
}

