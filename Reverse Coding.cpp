#define mod (int)(1e9 + 7)
int sumOfNaturals(int n)
{
    int first, second;
    if (n % 2 == 0)
    {
        first = n / 2;
        second = n + 1;
    }
    else
    {
        first = (n + 1) / 2;
        second = n;
    }
    return (first * 1LL * second) % mod;
}