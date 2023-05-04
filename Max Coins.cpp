#include<bits/stdc++.h>
using namespace std;
int f(int ind,vector<vector<int>>& ranges,int count,vector<vector<int>>& dp)
{
    if(count==2) return 0;
    if(ind==ranges.size()) return 0;
    if(dp[ind][count]!=-1) return dp[ind][count];
    int take=ranges[ind][2];
    int nextInd=ranges.size();
    int low=ind+1,high=ranges.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ranges[mid][0]>=ranges[ind][1])
        {
            nextInd=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    take+=f(nextInd,ranges,count+1,dp);
    int nottake=f(ind+1,ranges,count,dp);
    return dp[ind][count]=max(take,nottake);
    
}
int maxCoins(int n,vector<vector<int>> &ranges){
    sort(ranges.begin(),ranges.end());
    vector<vector<int>> dp(n+1,vector<int>(3,-1));
    return f(0,ranges,0,dp);
}