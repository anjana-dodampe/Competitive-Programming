#include <bits/stdc++.h>

using namespace std;

class Edge
{
  public:
    int to;
    Edge *sibling;
};

class Vertex
{
  public:
    int val;
    int visited;
    Edge *edge;
    Vertex *sibling;
};

Vertex *START = NULL;

void addVertex(int value)
{
    if (START == NULL)
    {
        START = new Vertex();
        START->val = value;
    }
    else
    {
        Vertex *PTR = START;
        while (PTR->sibling != NULL)
        {
            PTR = PTR->sibling;
        }
        Vertex *newVertex = new Vertex();
        newVertex->val = value;
        PTR->sibling = newVertex;
    }
}

void addEdge(int from, int to)
{
    Vertex *PTR = START;
    while (PTR != NULL && PTR->val != from)
    {
        PTR = PTR->sibling;
    }
    if (PTR == NULL)
    {
        cout << "There is no such vertex as " << from << endl;
    }
    else
    {
        if (PTR->edge == NULL)
        {
            Edge *newEdge = new Edge();
            newEdge->to = to;
            PTR->edge = newEdge;
        }
        else
        {
            Edge *EPTR = PTR->edge;
            while (EPTR->sibling != NULL)
            {
                EPTR = EPTR->sibling;
            }
            Edge *newEdge = new Edge();
            newEdge->to = to;
            EPTR->sibling = newEdge;
        }
    }
}

Vertex *findVertex(int key)
{
    Vertex *PTR = START;
    while (PTR != NULL && PTR->val != key)
    {
        PTR = PTR->sibling;
    }
    return PTR;
}

void resetTraverse()
{
    Vertex *PTR = START;

    while (PTR != NULL)
    {
        PTR->visited = 0;
        PTR = PTR->sibling;
    }
}

void bfs(Vertex *start)
{
    resetTraverse();
    queue<Vertex *> bfsQueue;
    bfsQueue.push(start);

    while (!bfsQueue.empty())
    {
        Vertex *vt = bfsQueue.front();
        cout << vt->val << endl;
        vt->visited = 1;
        bfsQueue.pop();
        Edge *PTR = vt->edge;
        while (PTR != NULL)
        {
            Vertex *adj = findVertex(PTR->to);
            if (adj->visited == 0)
            {
                bfsQueue.push(adj);
            }
            PTR = PTR->sibling;
        }
    }
}

void dfs(Vertex *start)
{

    start->visited = 1;
    cout << start->val << endl;
    Edge *PTR = start->edge;
    while (PTR != NULL)
    {
        Vertex *vt = findVertex(PTR->to);
        if (vt->visited == 0)
        {
            dfs(vt);
        } else if (vt->visited == 1) {
            cout << "Cycle found!" << endl;
        }
        PTR = PTR->sibling;
    }
    start->visited = 0;
}

int main(int argc, char const *argv[])
{
    addVertex(1);
    addVertex(2);
    addVertex(3);
    addVertex(4);
    addVertex(5);
    addVertex(6);

    addEdge(2, 3);
    addEdge(3, 1);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 2);
    addEdge(1, 6);
    addEdge(6, 5);

    Vertex *start = findVertex(2);
    dfs(start);

    return 0;
}