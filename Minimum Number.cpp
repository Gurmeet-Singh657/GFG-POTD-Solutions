#include<bits/stdc++.h>
using namespace std;
int minimumNumber(int n, vector<int> &arr)
{
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        g = __gcd(g, arr[i]);
    }
    return g;
}