#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    string t;
    cin >> n >> k >> t;

    for (size_t i = 0; i < n / 2; i++)
    {
        string front = t.substr(0, n / 2 - i);
        string back = t.substr(n / 2 + i + 1, n / 2 - i);
        if (front == back)
        {
            // cout << i << "\n";
            for (size_t j = 0; j < k; j++)
            {
                cout << front;
                cout << t.substr(n / 2 - i, n - 2 * (n / 2 - i));
            }
            cout << front;
            return 0;
        }
    }

    for (size_t j = 0; j < k; j++)
    {
        cout << t;
    }

    return 0;
}
