#include<bits/stdc++.h>
using namespace std;
long long f(int ind,vector<int>& A,int n,bool flag,vector<vector<int>>& dp)
{
    if(ind==n) return 0;
    if(dp[ind][flag]!=-1) return dp[ind][flag];
    long long nottake=-1e9;
    if(flag==false) // No Problem
    {
        nottake=f(ind+1,A,n,true,dp);
    }
    else // We have to take now
    {
        nottake=-1e9; // Should not be considered
    }
    long long take=A[ind]+f(ind+1,A,n,false,dp);
    return dp[ind][flag]=max(take,nottake);
}
long long findMaxSubsetSum(int N, vector<int> &A) {
    vector<vector<int>> dp(N+1,vector<int>(2,-1));
    return f(0,A,N,0,dp);
}