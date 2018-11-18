#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        int S, E;
        cin >> S >> E;
        map<int, int> hash;
        int arr[E];
        for (size_t j = 0; j < E; j++)
        {
            cin >> arr[j];
            if (hash[arr[j]] > 0)
                continue;
            hash[arr[j]] = j;
        }
        bool isFlag = true;
        int mini = E;
        int first, second;
        for (size_t j = 0; j < E; j++)
        {
            int rem = S - arr[j];
            if (hash[rem] != NULL && hash[rem] > j)
            {
                if (mini > hash[rem])
                {
                    first = arr[j];
                    second = arr[hash[rem]];
                    mini = hash[rem];
                    isFlag = false;
                }
            }
        }
        if (isFlag)
        {
            cout << "!OK" << endl;
        } else {
            cout << min(first, second) << " " << max(first, second) << endl;
        }
    }

    return 0;
}
