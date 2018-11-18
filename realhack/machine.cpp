#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, l, t;
    cin >> n >> l >> t;

    vector<char> m(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> m[i];
    }

    while (t > 0)
    {
        for (size_t j = 0; j < n - 1 - t; j++)
        {
            if (m[j] == 'D' && m[j + t] == 'N')
            {
                m[j] = 'N';
                m[j + t] = 'D';
                t++;
            }
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << m[i];
    }

    return 0;
}
