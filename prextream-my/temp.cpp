#include <bits/stdc++.h>

using namespace std;

int sherlockAndAnagrams(string s)
{
    int count = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        
        for (size_t j = i; j < s.size(); j++)
        {
            string sub = s.substr(i, j);
            string rev = sub.substr(0, sub.size());
            reverse(rev.begin(), rev.end());
            if (sub == rev)
            {
                cout << sub << " " << rev << endl;

                count++;
            }
        }
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
