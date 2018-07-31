#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> a;
    vector<int> b;
    int n, x;
    cin >> n >> x;
    a.reserve(n);
    b.reserve(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool found = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        {
            if (a[i] == a[j] && i != j) {
                cout << 0;
                return 0;
            }
        }
    }
        for(int i = 0; i < n; i++)
        {
            b[i] = a[i] & x;
        }
        bool changed = false;
        int i, j;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++)
            {
                if (b[i] == b[j] && i != j) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            } else if (a[i] != b[i]) {
                changed = true;
            }
        }        
        if (!found && !changed) {
            cout << -1;
            return 0;
        } else if (a[i] != b[i] && a[j] != b[j]) {
            // cout << a[i] << "," << b[i] << "," << a[j] << "," << b[j];
            cout << 2;
        } else {
            cout << 1;

        }
    return 0;
}
