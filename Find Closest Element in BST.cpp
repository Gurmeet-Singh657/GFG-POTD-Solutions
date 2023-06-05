int minDiff(Node *root, int K)
{
    if (root == NULL)
        return 1e9;
    if (root->data == K)
    {
        return 0;
    }
    else if (root->data > K)
    {
        int curr = abs(root->data - K);
        return min(curr, minDiff(root->left, K));
    }
    else
    {
        int curr = abs(root->data - K);
        return min(curr, minDiff(root->right, K));
    }
    return 0;
}