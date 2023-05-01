#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution
{
public:
    string f(Node *root, unordered_map<string, int> &mp)
    {
        if (root == NULL)
            return "";

        string curr = "";
        curr.push_back('#');
        curr += to_string(root->data);
        curr.push_back('$');
        for (auto it : root->children)
        {
            string temp1 = f(it, mp);
            curr += temp1;
        }
        curr.push_back('#');
        mp[curr]++;
        return curr;
    }
    int duplicateSubtreeNaryTree(Node *root)
    {
        unordered_map<string, int> mp;
        f(root, mp);
        int count = 0;
        for (auto it : mp)
        {
            if (it.second > 1)
                count++;
        }
        return count;
    }
};