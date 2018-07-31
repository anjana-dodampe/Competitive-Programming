#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 0;
    int y = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        x += e;
    }
    for(int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        y += e;
    }
    
    if (x >= y) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    
    return 0;
}
