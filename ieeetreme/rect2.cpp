#include <bits/stdc++.h>

using namespace std;

int maxSubArraySum(vector<int64_t> a) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < a.size(); i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 

int minSubArraySum(vector<int64_t> a) 
{ 
    int min_so_far = INT_MAX, min_ending_here = 0; 
  
    for (int i = 0; i < a.size(); i++) 
    { 
        min_ending_here = min_ending_here + a[i]; 
        if (min_so_far > min_ending_here) 
            min_so_far = min_ending_here; 
  
        if (min_ending_here > 0) 
            min_ending_here = 0; 
    } 
    return min_so_far; 
} 

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<int64_t> n;
    vector<int64_t> m;
    for (size_t i = 0; i < N; i++)
    {
        int64_t in;
        cin >> in;
        n.push_back(in);
    }
    for (size_t i = 0; i < M; i++)
    {
        int64_t in;
        cin >> in;
        m.push_back(in);
    }

    int nMax = maxSubArraySum(n);
    int mMax = maxSubArraySum(m);

    int nMin = minSubArraySum(n);
    int mMin = minSubArraySum(m);

    // cout << mMin << " " <<  nMin << endl;
    // cout << nMax << " " << mMax << endl;

    vector<int> maxV;
    maxV.push_back(mMin * nMin);
    maxV.push_back(mMax * nMin);
    maxV.push_back(mMax * nMax);
    maxV.push_back(mMin * nMax);

    cout << *max_element(maxV.begin(), maxV.end()) << endl;

    return 0;
}
