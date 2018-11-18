#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for(size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    int max = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        sum += arr[i];
    }
    int rem = 2 * sum - (max * n) + 1;
    float inc = (float) rem / n;
    if (inc < 0) {
        cout << max << endl;
        return 0;
    }
    // if (rem % n != 0) {
    //     inc++;
    // }
    // cout << sum << endl;
    // cout << max * n << endl;
    // cout << rem << endl;
    // cout << inc << endl;
    cout << ceil(max + inc) << endl;
    return 0;
}
