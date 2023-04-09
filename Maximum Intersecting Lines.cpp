#include<bits/stdc++.h>
using namespace std;
int maxIntersections(vector<vector<int>> lines, int N)
{
    map<int, int> mp;
    for (auto it : lines)
    {
        // (s,e) freq[s]++, freq[e+1]--
        int s = it[0], e = it[1];
        mp[s]++;
        mp[e + 1]--;
    }
    int maxi = 1;
    int presum = 0; // it shows the frequency of every element
    for (auto it : mp)
    {
        presum += it.second;
        maxi = max(maxi, presum);
    }
    return maxi;
}