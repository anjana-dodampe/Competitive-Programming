#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, Q;
    cin >> N;
    vector<int> p;
    map<int, bool> hash;
    for (size_t i = 0; i < N; i++)
    {
        int in;
        cin >> in;
        p.push_back(in);
        hash[in] = true;
    }
    cin >> Q;
    vector<int> queries;
    for (size_t i = 0; i < Q; i++) {
        int in;
        cin >> in;
        queries.push_back(in);
    }
    for (int q: queries)
    {
        bool yes = false;
        for (size_t j = 0; j < N; j++)
        {
            for (size_t k = j; k < N; k++)
            {
                cout << q << " " << (p[j] | p[k]) << endl;
                if (q == (int) (p[j] | p[k])) {
                    yes = true;
                    break;
                }
            }
            if (yes)
                break;
        }
        if (yes) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
