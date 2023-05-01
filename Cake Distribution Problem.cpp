#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(ll mid, vector<int> &arr, int N, int K)
{
    ll sum = 0;
    int count = 0;
    // Aim - Number of pieces > = k
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        if (sum >= mid)
        {
            count++;
            sum = 0;
        }
    }
    return count >= K + 1;
}
int maxSweetness(vector<int> &sweetness, int N, int K)
{
    ll start = 1, end = (ll)(1e14);
    ll ans = -1;
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        if (check(mid, sweetness, N, K))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}