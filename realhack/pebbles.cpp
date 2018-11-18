#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int g;
    cin >> g;

    for (size_t i = 0; i < g; i++)
    {
        int n;
        vector<int> p(n);
        for (size_t j = 0; j < n; j++)
        {
            cin >> p[j];
        }

        bool dulith = true;
        while (p.size() > 0) {
            vector<int>::iterator mx =  max_element(p.begin(), p.end());
            p.erase(mx, p.end());
            dulith = !dulith;
        }
        
        if (dulith) {
            cout << "DULITH" << endl;
        } else {
            cout << "DHANIKA" << endl;
        }
        
    }

    return 0;
}
