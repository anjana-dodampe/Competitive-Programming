#include <bits/stdc++.h>

using namespace std;

#define MAX 2019

vector<int> g[MAX];
bool visited[MAX];
int dis[MAX];
queue<int> q;

void resetVisited()
{
    for (size_t i = 0; i < MAX; i++)
    {
        visited[i] = false;
    }
}

void dfs(int start)
{
    if (visited[start])
    {
        cout << "Cycle found" << endl;
        return;
    }
    // Process data
    cout << start << endl;
    visited[start] = true;

    for (auto s : g[start])
    {
        dfs(s);
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

        for (int adj : g[vertex])
        {
            if (visited[adj])
            {
                cout << "Cycle found" << endl;
                continue;
            }
            visited[adj] = true;
            dis[adj] = dis[vertex] + 1
            q.push(adj);
        }
    }
}

int main(int argc, char const *argv[])
{
    g[2018].push_back(2 );
    g[2].push_back(3);
    g[2].push_back(4);
    g[3].push_back(1);
    g[4].push_back(3);

    resetVisited();
    dfs(1);
    cout << "=================" << endl;
    resetVisited();
    bfs(2);
    return 0;
}
