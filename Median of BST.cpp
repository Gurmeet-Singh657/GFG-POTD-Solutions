void Inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    Inorder(root->left, ans);
    ans.push_back(root->data);
    Inorder(root->right, ans);
}
float findMedian(struct Node *root)
{
    vector<int> ans;
    Inorder(root, ans);
    int n = ans.size();
    if (n % 2 == 0)
        return float(ans[n / 2 - 1] + ans[n / 2]) / 2.0;
    return ans[n / 2];
}