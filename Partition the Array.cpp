#inlude<bits/stdc++.h>
using namespace std;
// further 2 paritions with minimum absolute difference
pair<long long, long long> solve(long long presum[], int start, int end)
{
    int low = start, high = end - 1;
    long long leftans = 0, rightans = 1e9;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long leftsum = presum[mid] - (start - 1 >= 0 ? presum[start - 1] : 0);
        long long rightsum = presum[end] - presum[mid];
        if (abs(rightans - leftans) > abs(rightsum - leftsum))
        {
            rightans = rightsum;
            leftans = leftsum;
        }
        if (leftsum < rightsum)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return {leftans, rightans};
}
long long minDifference(int N, vector<int> &arr)
{
    long long presum[N] = {0};
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            presum[i] += presum[i - 1];
        presum[i] += arr[i];
    }
    long long minans = 1e9;
    for (int i = 1; i <= N - 3; i++) // 2 partitions
    {
        auto fs = solve(presum, 0, i);
        auto ss = solve(presum, i + 1, N - 1);
        long long first = fs.first;
        long long second = fs.second;
        long long third = ss.first;
        long long fourth = ss.second;
        long long maxi = max(max(first, second), max(third, fourth));
        long long mini = min(min(first, second), min(third, fourth));
        minans = min(minans, maxi - mini);
    }
    return minans;
}