#include<bits/stdc++.h>
using namespace std;
bool makePalindrome(int n,vector<string> &arr){
    unordered_map<string,int> mp;
    for(auto it:arr)
    {
        string rev=it;
        reverse(rev.begin(),rev.end());
        if(mp.find(rev)!=mp.end())
        {
            mp[rev]--;
            if(mp[rev]==0) mp.erase(rev);
        }
        else
        {
            mp[it]++;
        }
    }
    if(mp.size()==0) return true;
    if(mp.size()==1)
    {
        string curr=mp.begin()->first;
        string rev=curr;
        reverse(rev.begin(),rev.end());
        return rev==curr;
    }
    return false;
}