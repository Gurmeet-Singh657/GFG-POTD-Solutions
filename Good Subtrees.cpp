#include<bits/stdc++.h>
using namespace std;
int f(Node *root, int k, int freq[])
{
    if (root == NULL)
        return 0;

    int ans = 0;
    int leftfreq[26] = {0}, rightfreq[26] = {0};
    ans += f(root->left, k, leftfreq);
    ans += f(root->right, k, rightfreq);
    freq[root->data]++;

    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        freq[i] += leftfreq[i] + rightfreq[i];
        if (freq[i] > 0)
            count++;
    }
    if (count <= k)
        ans++;
    return ans;
}
int goodSubtrees(Node *root, int k)
{
    int freq[26] = {0};
    return f(root, k, freq);
}