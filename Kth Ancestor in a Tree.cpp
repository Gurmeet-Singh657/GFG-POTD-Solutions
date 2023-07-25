int f(Node *root, int &k, int node)
{
    if (root == NULL)
        return -1;
    int left = f(root->left, k, node);
    if (left != -1)
    {
        k -= 1;
        if (k == 0)
            return root->data;
        return left;
    }

    int right = f(root->right, k, node);
    if (right != -1)
    {
        k -= 1;
        if (k == 0)
            return root->data;
        return right;
    }

    if (root->data == node)
    {
        return node;
    }
    return -1;
}
// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    int ans = f(root, k, node);
    if (k > 0)
        return -1;
    return ans;
}