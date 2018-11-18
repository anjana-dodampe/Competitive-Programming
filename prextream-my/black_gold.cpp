#include <bits/stdc++.h>

using namespace std;

class Edge
{
  public:
    int to;
    int speed;
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

void addEdge(int from, int to, int speed)
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
            newEdge->speed = speed;
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
            newEdge->speed = speed;
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

int findSpeed(Vertex *v, int end)
{
    Edge *PTR = v->edge;
    cout << v->val << " to " << PTR->to << " " << PTR->speed << endl;
    int min = -1;
    while (PTR != NULL)
    {
        if (PTR->to != end)
        {
            Vertex *x = findVertex(PTR->to);
            int speed = findSpeed(x, end);

            if (min == -1)
            {
                min == speed;
            }
            else if (min > speed)
            {
                min == speed;
            }
        }
        PTR = PTR->sibling;
    }
    return min;
}

int main(int argc, char const *argv[])
{
    int n, first, last;
    cin >> n >> first >> last;

    for (size_t i = first; i < last; i++)
    {
        addVertex(i);
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        int start, end, speed;
        cin >> start >> end >> speed;
        addEdge(start, end, speed);
    }

    Vertex *s = findVertex(first);
    cout << findSpeed(s, last);

    return 0;
}