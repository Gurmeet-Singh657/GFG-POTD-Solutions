#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<long long> smallerSum(int n,vector<int> &arr){
    map<ll,ll> mp; // frequency of every element
    unordered_map<ll,ll> Presum; // Prefix sum till every element
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    ll prevsum=0;
    for(auto it:mp)
    {
        Presum[it.first]=prevsum;
        prevsum+=it.second*it.first; 
    }
    vector<ll> ans;
    for(int i=0;i<n;i++)
    {
        ll currans=Presum[arr[i]];
        ans.push_back(currans);
    }
    return ans;
}