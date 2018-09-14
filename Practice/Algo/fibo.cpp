#include <bits/stdc++.h>

using namespace std;

map<int, int> mem;

int fibo(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        if (mem[n])
        {
            return mem[n];
        }
        else
        {
            int val = fibo(n - 1) + fibo(n - 2);
            mem[n] = val;
            return val;
        }
    }
}

main(int argc, char const *argv[])
{
    cout << "Enter number to find the fibonacci no of that: ";
    int n;
    cin >> n;
    cout << "Result: " << fibo(n) << endl;
    return 0;
}
