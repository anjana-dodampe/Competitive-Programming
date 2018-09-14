#include <bits/stdc++.h>

using namespace std;

int coins[] = {1, 5, 8, 10};
map<int, int> mem;

int countCoin(int amount)
{
    int count = -1;
    for (int i = 3; i >= 0; i--)
    {
        cout << "loop" << endl;
        int sub = 0;
        int remain = amount - coins[i];
        if (remain < 0)
        {
            continue;
        }
        else if (remain == 0)
        {
            sub = 1;
        }
        else
        {
            if (mem[remain])
            {
                sub = mem[remain];
            }
            else
            {
                sub = 1 + countCoin(remain);
                mem[remain] = sub;
            }
        }
        if (sub < count || count == -1)
        {
            count = sub;
        }
    }
    return count;
}

main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << countCoin(n) << endl;
    return 0;
}
