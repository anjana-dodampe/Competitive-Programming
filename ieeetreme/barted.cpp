#include <bits/stdc++.h>

using namespace std;

#define MAX 50

vector<pair<int, int>> g[MAX];
bool visited[MAX];
int dis[MAX];
queue<int> q;
vector<string> key;

void resetVisited()
{
    for (size_t i = 0; i < MAX; i++)
    {
        visited[i] = false;
    }
}

void dfs(int start, int key)
{
    if (visited[start])
    {
        cout << "Cycle found" << endl;
        return;
    }
    // Process data

    if (key == start)
    {
        cout << "Key exists: " << key << endl;
        return;
    }
    cout << start << endl;
    visited[start] = true;

    for (pair<int, int> s : g[start])
    {
        dfs(s.first, key);
    }
}

void bfs(int start)
{
    visited[start] = true;
    q.push(start);
    dis[start] = 0;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        // Process data
        cout << vertex << endl;

        for (auto adj : g[vertex])
        {
            if (visited[adj.first])
            {
                cout << "Cycle found" << endl;
                continue;
            }
            visited[adj.first] = true;
            dis[adj.first] = dis[vertex] + 1;
            q.push(adj.first);
        }
    }
}

int main(int argc, char const *argv[])
{
    int N, Q;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        string A, B;
        int r;
        cin >> A >> B >> r;
        auto index = find(key.begin(), key.end(), A);
        int aptr;
        if (index != key.end())
        {
            aptr = index - key.begin();
        }
        else
        {
            aptr = key.size();
            key.push_back(A);
        }
        index = find(key.begin(), key.end(), B);
        int bptr;
        if (index != key.end())
        {
            bptr = index - key.begin();
        }
        else
        {
            bptr = key.size();
            key.push_back(B);
        }
        g[aptr].push_back({bptr, r});
        g[bptr].push_back({aptr, r});
    }

    for (auto a : key)
    {
        cout << a << endl;
    }

    cin >> Q;

    for (size_t i = 0; i < Q; i++)
    {
        string K, L;
        cin >> K >> L;
        cout << K << L;
        int k = find(key.begin(), key.end(), K) - key.begin();
        int l = find(key.begin(), key.end(), L) - key.begin();

        if (k == l)
        {
            cout << 1;
        }
        else
        {
            resetVisited();
            dfs(k, l);
        }
    }
    // cout << "=================" << endl;
    // resetVisited();
    // bfs(2);
    return 0;
}