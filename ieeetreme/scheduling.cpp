#include <bits/stdc++.h>

using namespace std;

auto endSort = [](const std::tuple<int, int, int, int> &lhs,
                  const std::tuple<int, int, int, int> &rhs) {
    return get<2>(lhs) < get<2>(rhs);
};

int main(int argc, char const *argv[])
{
    vector<tuple<int, int, int, int>> stars;
    int N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int s, f, w;
        cin >> s >> f >> w;
        stars.push_back({i + 1, s, f, w});
    }

    sort(stars.begin(), stars.end(), endSort);

    // cout << "-----------" << endl;
    auto s = stars[0];
    int star = get<0>(s);
    int start = get<1>(s);
    int finish = get<2>(s);
    int weight = get<3>(s);

    // cout << "-----------" << endl;
    vector<int> sumA;
    sumA.push_back(weight);

    map<int, int> over;
    over[0] = 1;
    for (size_t j = 1; j < stars.size(); j++)
    {
        auto nextStar = stars[j];
        int nstar = get<0>(nextStar);
        int nextStart = get<1>(nextStar);
        int nextFinish = get<2>(nextStar);
        int nextWeight = get<3>(nextStar);

            cout << "lol: " << nstar << " " << nextStart << " " << nextFinish << " " << nextWeight << endl;

        if (nextStart > finish)
        {
            cout << "Next: " << nstar << " " << nextStart << " " << nextFinish << " " << nextWeight << endl;
            over[j] = 1;
            finish = nextFinish;
            sumA.push_back(nextWeight);
        }
        cout << "EE: " << finish << endl;
        for (size_t e = 1; e < stars.size(); e++)
        {
            if (over[e] == 0)
            {
                auto overStar = stars[e];
                int ostar = get<0>(overStar);
                int overStart = get<1>(overStar);
                int overFinish = get<2>(overStar);
                int overWeight = get<3>(overStar);
                if (overStart > start && overFinish < finish)
                {
                    cout << "Over: " << ostar << " " << overStart << " " << overFinish << " " << overWeight << endl;
                    over[e] = 1;
                    sumA.pop_back();
                    int last = *sumA.end();
                    sumA.pop_back();
                    int lastb = *sumA.end();
                    cout << "fuck" << last << " " << lastb << endl;
                    if (overWeight > last + lastb)
                    {
                        cout << "Change" << endl;
                        sumA.push_back(overWeight);
                        finish = overFinish;
                    } else {
                        cout << "Revert" << endl;
                        sumA.push_back(lastb);
                        sumA.push_back(last);
                    }
                }
            }
        }
    }

    // }

    // int max = 0;
    // int sum = 0;

    // if (sum > max)
    //     max = sum;
    // cout << finish << endl;
    int sum = 0;
    
    for(int s: sumA)
    {
        sum += s;
    }
    
    cout << sum << endl;

    return 0;
}
