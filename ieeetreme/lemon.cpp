#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M, S;
    cin >> N >> M >> S;
    int n = N - 1;
    int steps = ceil(log2(N * 1.0f));
    cout << steps * S + n * M << endl;
    return 0;
}
