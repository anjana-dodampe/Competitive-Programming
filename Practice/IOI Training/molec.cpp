#include <bits/stdc++.h>

using namespace std;

vector<int> pos;
int v[200000];
// vector<int> dex;

// int srch(int l, int u, int a[], int n, int i)
// {
//     if (i == n)
//     {
//         int sum = 0;
//         for (int x = 0; x < dex.size(); x++)
//         {
//             // cout << a[dex[x]] << " ";
//             sum += a[dex[x]];
//         }
//         // cout << "\n";
//         if (sum >= l && sum <= u)
//         {
//             cout << dex.size() << "\n";
//             for (int x = 0; x < dex.size(); x++)
//             {
//                 cout << dex[x] << " ";
//             }
//             cout << "\n";
//             return dex.size();
//         }
//         return 0;
//     }
//     else
//     {
//         int x = srch(l, u, a, n, i + 1);
//         if (x != 0)
//         {
//             return x;
//         }
//         dex.push_back(i);
//         x = srch(l, u, a, n, i + 1);
//         dex.pop_back();
//         if (x != 0)
//         {
//             return x;
//         }
//         return 0;
//     }
// }

int find_subset(int l, int u, int w[], int n)
{
    copy(w, w + n, v);
    int sum = 0;
    for (int x = n - 1; x >= 0; x--)
    {
        auto r = max_element(w, w + n);
        int sub = *r;
        if (sub <= u)
        {
            sum += sub;
            pos.push_back(r - w);
            if (sum >= l && sum <= u)
            {
                cout << pos.size() << "\n";
                for (size_t i = 0; i < pos.size(); i++)
                {
                    cout << pos[i] << " ";
                }
                cout << "\n";
                return pos.size();
            }
            if (sum > u)
            {
                sum -= sub;
                pos.pop_back();
            }
        }
        *r = -1;
    }
    cout << 0 << "\n";
    return 0;
}

int main(int argc, char const *argv[])
{
    int n, l, u;
    cin >> n >> l >> u;
    int arr[200000];

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    find_subset(l, u, arr, n);
    return 0;
}
