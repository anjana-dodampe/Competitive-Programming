#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll fac(ll n) {
    if (n == 0) 
        return 1LL;
    else if (n == 1)
        return 1LL;
    else
        return n * fac(n - 1);
}

int main(int argc, char const *argv[])
{
    ll k, n = 4;
    cin >> k;
    ll count = fac(n + k - 1)/(fac(n - 1)*fac(k));
    cout << count;
    return 0;
}
