#include<bits/stdc++.h>
using namespace std;
char solve(int freq[], int k)
{
    int count = 0;
    for (int i = 25; i >= 0; i--)
    {
        count += freq[i];
        if (count >= k)
            return i + 'a';
    }
    return '*';
}
vector<char> easyTask(int n, string s, int q, vector<vector<string>> &queries)
{
    vector<char> ans;

    for (int i = 0; i < queries.size(); i++)
    {
        int queryno = stoi(queries[i][0]);
        if (queryno == 1)
        {
            int ind = stoi(queries[i][1]);
            char ch = queries[i][2][0];
            s[ind] = ch;
        }
        else
        {
            int left = stoi(queries[i][1]);
            int right = stoi(queries[i][2]);
            int k = stoi(queries[i][3]);
            int freq[26] = {0};
            for (int k = left; k <= right; k++)
            {
                int ele = s[k] - 'a';
                freq[ele]++;
            }
            char ch = solve(freq, k);
            ans.push_back(ch);
        }
    }
    return ans;
}