#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution
{
public:
    int arr[5] = {1, 3, 5, 7, 9};
    long long findNumber(long long N)
    {
        long long ans = 0;
        long long num = 1;
        while (N > 0)
        {
            int rem = (N - 1) % 5;
            ans = ans + arr[rem] * num;
            N = (N - 1) / 5;
            num *= 10;
        }
        return ans;
    }
};