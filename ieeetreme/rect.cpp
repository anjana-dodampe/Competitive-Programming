#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<int> n;
    vector<int> m;
    for (size_t i = 0; i < N; i++)
    {
        int in;
        cin >> in;
        n.push_back(in);
    }
    for (size_t i = 0; i < M; i++)
    {
        int in;
        cin >> in;
        m.push_back(in);
    }

    vector<int> ns;
    vector<int> nx;
    int sum = 0;
    for (int e : n)
    {
        if (e > 0)
        {
            if (sum < 0)
            {
                nx.push_back(sum);
                sum = e;
            }
            else
            {
                sum += e;
            }
        }
        else if (e < 0)
        {
            if (sum > 0)
            {
                ns.push_back(sum);
                sum = e;
            }
            else
            {
                sum += e;
            }
        }
    }
    if (sum > 0)
    {
        ns.push_back(sum);
    }
    else if (sum < 0)
    {
        nx.push_back(sum);
    }

    vector<int> ms;
    vector<int> mx;
    sum = 0;
    for (int e : m)
    {
        if (e > 0)
        {
            if (sum < 0)
            {
                mx.push_back(sum);
                sum = e;
            }
            else
            {
                sum += e;
            }
        }
        else if (e < 0)
        {
            if (sum > 0)
            {
                ms.push_back(sum);
                sum = e;
            }
            else
            {
                sum += e;
            }
        }
    }
    if (sum > 0)
    {
        ms.push_back(sum);
    }
    else if (sum < 0)
    {
        mx.push_back(sum);
    }

    // for (int e : ns)
    // {
    //     cout << e << endl;
    // }
    // cout << "---------" << endl;
    // for (int e : nx)
    // {
    //     cout << e << endl;
    // }

    // cout << "!!!!!!" << endl;

    // for (int e : ms)
    // {
    //     cout << e << endl;
    // }
    // cout << "---------" << endl;
    // for (int e : mx)
    // {
    //     cout << e << endl;
    // }

    int max = 0;
    for (int e : ns)
    {
        for (int a : ms)
        {
            int mult = e * a;
            if (mult > max)
                max = mult;
        }
    }

    for (int e : nx)
    {
        for (int a : mx)
        {
            int mult = e * a;
            if (mult > max)
                max = mult;
        }
    }

    cout << max << endl;

    return 0;
}
