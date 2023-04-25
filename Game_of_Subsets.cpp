#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution
{
public:
#define mod (int)(1e9 + 7)
    vector<int> mappings[31];
    void CreateMapping()
    {
        for (int i = 1; i <= 30; i++)
        {
            vector<int> curr;
            int num = i;
            int divi = 2;
            bool flag = true;
            while (divi * divi <= num)
            {
                if (num % divi == 0)
                {
                    num /= divi;
                    curr.push_back(divi);
                }
                if (num % divi == 0)
                {
                    flag = false;
                    break;
                }
                divi++;
            }
            if (num > 1)
            {
                curr.push_back(num);
            }
            if (flag == true)
            {
                mappings[i].insert(mappings[i].begin(), curr.begin(), curr.end());
            }
        }
    }
    int f(int ind, vector<int> &curr, int bitmask, int count[], map<pair<int, int>, int> &mp)
    {
        if (ind == curr.size())
        {
            if (bitmask == 0)
                return 0;
            return 1;
        }
        if (mp.find({ind, bitmask}) != mp.end())
            return mp[{ind, bitmask}];
        vector<int> currmap = mappings[curr[ind]];
        bool flag = true;
        int currmask = 0;
        for (auto it : currmap)
        {
            if (((1 << it) & bitmask) != 0)
            {
                flag = false;
                break;
            }
            currmask |= (1 << it);
        }
        int take = 0;
        if (flag)
        {
            take = (count[curr[ind]] * 1LL * f(ind + 1, curr, bitmask | currmask, count, mp)) % mod;
        }
        int nottake = f(ind + 1, curr, bitmask, count, mp);
        return mp[{ind, bitmask}] = (take + 0LL + nottake) % mod;
    }
    int binExp(int n, int x)
    {
        int ans = 1;
        while (x)
        {
            if (x & 1)
                ans = (ans * 1LL * n) % mod;
            n = (n * 1LL * n) % mod;
            x >>= 1;
        }
        return ans;
    }
    int goodSubsets(vector<int> &arr, int n)
    {
        CreateMapping();
        int count[31] = {0};
        for (auto it : arr)
            count[it]++;
        vector<int> curr;
        int countones = count[1];
        for (int i = 2; i <= 30; i++)
        {
            if (count[i] > 0 && mappings[i].size() > 0)
                curr.push_back(i);
        }
        int bitmask = 0;
        int OnesContr = binExp(2, countones);
        map<pair<int, int>, int> mp;
        return (OnesContr * 1LL * f(0, curr, bitmask, count, mp)) % mod;
    }
};