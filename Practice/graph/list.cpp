#include <bits/stdc++.h>

using namespace std;

map<string, list<string>> graph;
map<string, bool> visited;

void resetVisited()
{
    for (pair<string, bool> vertex : visited)
    {
        // cout << "reset " << vertex.first << endl;
        visited[vertex.first] = false;
    }
}

bool bfs(string start, string key)
{
    if (visited[start] == true)
        return false;

    visited[start] = true;
    if (start == key)
    {
        return true;
    }
    list<string> adj = graph[start];

    for (string city : adj)
    {
        if (bfs(city, key))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int N, E;
    cin >> N >> E;
    for (size_t i = 0; i < N; i++)
    {
        string in;
        cin >> in;
        graph[in] = list<string>();
        visited[in] = false;
    }

    for (size_t i = 0; i < E; i++)
    {
        string from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    // cout << "-----------------" << endl;
    // for (pair<string, list<string>> p : graph)
    // {
    //     cout << p.first << p.second.size() << endl;
    // }

    cout << "-----------------" << endl;
    for (pair<string, list<string>> p : graph)
    {
        // cout << p.first << p.second.size() << endl;
        for (pair<string, list<string>> q : graph)
        {
            // cout << "loop" << endl;
            if (p.first != q.first)
            {
                resetVisited();
                if (bfs(p.first, q.first))
                {
                    cout << p.first << " " << q.first << " True" << endl;
                }
                else
                {
                    cout << p.first << " " << q.first << " False" << endl;
                }
            }
        }
    }
}