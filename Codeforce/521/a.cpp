#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    long long t;
    cin >> t;
    
    for(size_t i = 0; i < t; i++)
    {
        int a, b, k;
        cin >> a >> b >> k;
        int duoSteps = k / 2;
        int lastStep = k % 2;
        long long end = 0;
        end += (a - b) * duoSteps;
        if (lastStep > 0)
            end += a;
        cout << end << endl;
    }
    
    return 0;
}
