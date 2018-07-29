#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, a[1000], b[1000];
    double m, fuel = 0;
    cin >> n;
    cin >> m;
    for(size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= 1) {
            cout << -1;
            return 0;
        }   
    }
    for(size_t i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] <= 1) {
            cout << -1;
            return 0;
        }
    }
    fuel += m / (b[0] - 1); 
    // cout << fuel << " ";
    for(size_t i = n - 1; i > 0; i--)
    {
        fuel += (m + fuel) / (a[i] - 1); 
        // cout << fuel << " ";
        fuel += (m + fuel) / (b[i] - 1); 
        // cout << fuel << " ";
    }
    fuel += (m + fuel) / (a[0] - 1);
    cout << fuel;
    return 0;
}
