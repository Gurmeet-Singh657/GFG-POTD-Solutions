int f(int i,int price[],int rodLen,int n,vector<vector<int>>& dp)
{
    if(rodLen==0) return 0;
    if(i==n) return -1e9;
    if(dp[i][rodLen]!=-1) return dp[i][rodLen];
    int nottake=f(i+1,price,rodLen,n,dp);
    int take=-1e9;
    if(rodLen>=(i+1))
    take=price[i]+f(i,price,rodLen-(i+1),n,dp);
    return dp[i][rodLen]=max(take,nottake);
}
int cutRod(int price[], int n) {
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(0,price,n,n,dp);
}