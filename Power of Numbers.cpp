#define mod (int)(1e9 + 7)
long long power(int N, int R)
{
    long long ans = 1LL;
    while (R)
    {
        if (R & 1)
            ans = (ans * 1LL * N) % mod;
        N = (N * 1LL * N) % mod;
        R >>= 1;
    }
    return ans;
}