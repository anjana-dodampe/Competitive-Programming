#include <bits/stdc++.h>

using namespace std;

#define MAX 100;

vector<tuple<int, int, int>> g;
int dis[100];

int bellman()
{
    for (size_t i = 1; i < g.size(); i++)
    {
        dis[i] = INFINITY;
    }
    dis[0] = 0;
    for (size_t i = 0; i < g.size(); i++)
    {
        for (auto e: g)
        {
            int a, b, w;
            tie(a, b, w) = e;
            dis[b] = min(dis[b], dis[a] + w);
        }
    }
}

int main(int argc, char const *argv[])
{
    g.push_back({0, 1, 5});
    g.push_back({0, 3, 7});
    g.push_back({0, 2, 3});
    g.push_back({1, 5, 2});
    g.push_back({1, 3, 3});
    g.push_back({2, 3, 1});
    g.push_back({3, 5, 2});
    bellman();
    cout << dis[5] << endl;
    return 0;
}
