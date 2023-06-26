// Memoisation
// #define mod (int)(1e9+7)
// int f(int n,int r,vector<vector<int>>& dp)
// {
//     if(n<r) return 0;
//     if(r==0) return 1;
//     if(dp[n][r]!=-1) return dp[n][r];
//     return dp[n][r]=(f(n-1,r-1,dp)+0LL+f(n-1,r,dp))%mod;
// }
// int nCr(int n, int r){
//     vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
//     return f(n,r,dp);
// }

// Tabulation
// #define mod (int)(1e9+7)
// int nCr(int n, int r){
//     if(n<r) return 0;

//     vector<vector<int>> dp(n+1,vector<int>(n+1,0));

//     for(int i=0;i<=n;i++) dp[i][0]=1;

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=i;j++)
//         {
//             dp[i][j]=(dp[i-1][j-1]+0LL+dp[i-1][j])%mod;
//         }
//     }
//     return dp[n][r];
// }

// Space Optimisation
#define mod (int)(1e9 + 7)
int nCr(int n, int r)
{
    if (n < r)
        return 0;

    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    prev[0] = 1;
    curr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            curr[j] = (prev[j - 1] + 0LL + prev[j]) % mod;
        }
        prev = curr;
    }
    return curr[r];
}