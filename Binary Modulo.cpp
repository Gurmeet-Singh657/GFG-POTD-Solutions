#include<bits/stdc++.h>
using namespace std;
int modulo(string s, int m)
{
    int ans = 0;
    int a = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int currbit = s[i] - '0';
        ans = (ans + currbit * a) % m;
        a = (a * 2) % m;
    }
    return ans;
}