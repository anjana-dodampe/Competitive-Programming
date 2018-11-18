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
    // first direction
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
        if (PTR->edge == NULL) {
            Edge *newEdge = new Edge();
            newEdge->to = to;
            PTR->edge = newEdge;
        } else {
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
    // second direction
    while (PTR != NULL && PTR->val != to)
    {
        PTR = PTR->sibling;
    }
    if (PTR == NULL)
    {
        cout << "There is no such vertex as " << to << endl;
    }
    else
    {
        if (PTR->edge == NULL) {
            Edge *newEdge = new Edge();
            newEdge->to = from;
            PTR->edge = newEdge;
        } else {
            Edge *EPTR = PTR->edge;
            while (EPTR->sibling != NULL)
            {
                EPTR = EPTR->sibling;
            }
            Edge *newEdge = new Edge();
            newEdge->to = from;
            EPTR->sibling = newEdge;
        }
    }
}

void resetVertexes()
{
    Vertex *PTR = START;
    while (PTR != NULL)
    {
        PTR = PTR->sibling;
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

bool sub(Vertex *n, int d)
{
    cout << n->val << ", " << d << endl;
    if (d == 0) {
        if (mem[make_pair(n->val, d)]) {
            return false;
        } else {
            mem[make_pair(n->val, d)] = true;
            return true;
        }
    }
    Edge *PTR = n->edge;
    bool flag = false;
    int child = 0;
    while (PTR != NULL)
    {
        Vertex *x = findVertex(PTR->to);
        if (x->went == false) {
            child++;
            if (mem[make_pair(n->val, d)]) {}
            else {
                bool m = sub(x, d - 1);

                if (m) {
                    mem[make_pair(n->val, d)] = true;
                    flag = true;
                }
            }
        }
        PTR = PTR->sibling;
    }
    if (child == 0) {
        if (mem[make_pair(n->val, d)]) {}
        else {

                flag = true;
        }
    }
    return flag;
}

int main(int argc, char const *argv[])
{
    int n, d;
    cin >> n >> d;
    
    for (size_t i = 1; i <= n; i++)
    {
        addVertex(i);
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        addEdge(c1, c2);
    }

    int count = 0;

    for (size_t i = 1; i <= n; i++)
    {
        if (sub(findVertex(i), d)) {
            cout << "count" << endl;
            count++;
        } else
            cout << "not" << endl;
        resetVertexes();
    }

    cout << count << endl;

    return 0;
}