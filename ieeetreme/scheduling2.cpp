#include <bits/stdc++.h>

using namespace std;

struct Star 
{ 
    int start, finish, weight; 
}; 

bool endSort(Star s1, Star s2) 
{ 
    return s1.finish < s2.finish; 
} 

int latestNonOver(vector<Star> v, int i) 
{ 
    for (int j=i-1; j>=0; j--) 
    { 
        if (v[j].finish <= v[i].start) 
            return j; 
    } 
    return -1; 
} 

int findMaxVisibility(vector<Star> v, int n) 
{ 
    sort(v.begin(), v.begin() + n, endSort); 
   
    vector<int> table;
    table.reserve(n);
    table[0] = v[0].weight; 
  
    for (int i=1; i<n; i++) 
    { 
        int inclWeight = v[i].weight; 
        int l = latestNonOver(v, i); 
        if (l != -1) 
            inclWeight += table[l]; 
  
        table[i] = max(inclWeight, table[i-1]); 
    } 
  
    int result = table[n-1];  
  
    return result; 
}

int main(int argc, char const *argv[])
{
    vector<Star> stars;
    int N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int s, f, w;
        cin >> s >> f >> w;
        stars.push_back({s, f, w});
    }
    cout << findMaxVisibility(stars, stars.size()) << endl; 


    return 0;
}
