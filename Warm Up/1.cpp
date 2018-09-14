#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, p;
    cin >> n >> p;

    int total[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (size_t i = 0; i < n; i++)
    {
        int tseats = 0;
        int vote[10], seat;
        cin >> seat;
        int sum = 0;
        for (size_t j = 0; j < p; j++)
        {
            cin >> vote[j];
            sum += vote[j];
        }
        int seats[10];
        for (size_t j = 0; j < p; j++)
        {
            seats[j] = (seat * vote[j]) / sum;
            tseats += seats[j];
        }
        int rem = seat - tseats;
        while (rem > 0)
        {
            int *ele = max_element(vote, vote + p);
            int pos = ele - vote;
            seats[pos]++;
            vote[pos] = -1;
            rem--;
        }
        for (size_t j = 0; j < p; j++)
        {
            // cout << seats[j] << " ";
            total[j] += seats[j];
        }
        // cout << "\n";
    }

    for (size_t j = 0; j < p; j++)
    {
        cout << total[j] << " ";
    }

    return 0;
}
