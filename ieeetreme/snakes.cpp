#include <bits/stdc++.h>

using namespace std;

map<int, int> snakes;

void mergeSnakes(int start, int end)
{
    if (snakes[end] == 0)
    {
        return;
    }
    else
    {
        snakes[start] = snakes[end];
        mergeSnakes(start, snakes[start]);
    }
}

void addSnake(int B, int hx, int hy, int tx, int ty)
{
    int start, end;
    if (hy % 2 == 0)
    {
        if (ty % 2 == 0)
        {
            start = B * (hy - 1) + (B + 1 - hx);
            end = B * (ty - 1) + (B + 1 - tx);
        }
        else
        {
            start = B * (hy - 1) + (B + 1 - hx);
            end = B * (ty - 1) + tx;
        }
    }
    else
    {
        if (ty % 2 == 0)
        {
            start = B * (hy - 1) + hx;
            end = B * (ty - 1) + (B + 1 - tx);
        }
        else
        {
            start = B * (hy - 1) + hx;
            end = B * (ty - 1) + tx;
        }
    }
    snakes[start] = end;
    mergeSnakes(start, end);
}

int main(int argc, char const *argv[])
{
    int B, P, S, L, K;
    cin >> B >> P;
    cin >> S;

    for (size_t i = 0; i < S; i++)
    {
        int hx, hy, tx, ty;
        cin >> hx >> hy >> tx >> ty;
        addSnake(B, hx, hy, tx, ty);
    }
    cin >> L;

    for (size_t i = 0; i < L; i++)
    {
        int hx, hy, tx, ty;
        cin >> hx >> hy >> tx >> ty;
        addSnake(B, hx, hy, tx, ty);
    }

    int player = 0;
    int wonCount = 0;
    vector<int> pv;
    pv.reserve(P);

    cin >> K;
    cout << endl;
    for (size_t i = 0; i < K; i++)
    {
        int first, sec;
        if (wonCount > P)
        {
            cin >> first >> sec;
            continue;
        }
        if (pv[player] > (B * B))
            continue;

        cin >> first >> sec;
        int sum = first + sec;
        pv[player] += sum;
        // cout << "P" << player << " Dice: " << pv[player] << endl;
        if (snakes[pv[player]])
        {
            pv[player] = snakes[pv[player]];
            // cout << "P" << player << " Snake: " << pv[player] << endl;
        }
        if (pv[player] > B * B)
        {
            wonCount++;
            // cout << player + 1 << " winner" << endl;
        }
        player = (player + 1) % P;
    }

    for (size_t i = 0; i < P; i++)
    {
        if (pv[i] > B * B)
        {
            cout << i + 1 << " winner" << endl;
        }
    }

    return 0;
}
