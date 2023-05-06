#include<bits/stdc++.h>
using namespace std;
bool check(int N, int i, int k, int target, vector<int> &coins, int sum)
{
    if (k == 0 && target == sum)
        return true;

    if (k == 0)
        return false;

    if (i == N)
        return false;

    bool take = false;
    int accum = coins[i];
    for (int j = 0; j < k; j++)
    {
        if (sum + accum <= target && k - j - 1 >= 0)
        {
            take = take || check(N, i + 1, k - j - 1, target, coins, sum + accum);
            accum += coins[i];
        }
    }
    bool notake = check(N, i + 1, k, target, coins, sum);

    return take || notake;
}
bool makeChanges(int N, int K, int target, vector<int> &coins)
{
    // code here
    return check(N, 0, K, target, coins, 0);
}