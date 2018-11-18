#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    map<int, int> a;

    cin >> n;
    
    for(size_t i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        a[in] = i;
    }

    int count = 0;
    int pos = -1;
    
    int move[n];
    
    for(size_t i = 0; i < n; i++)
    {
        cin >> move[i];
    }
    
    for(size_t i = 0; i < n; i++)
    {
        int in = move[i];
        if (a[in] > pos) {
            cout << a[in] + 1 - count << " ";
            pos = a[in];
            count = a[in] + 1;
        } else {
            cout << 0 << " ";
        }
    }
    
    cout << endl;
    
    return 0;
}
