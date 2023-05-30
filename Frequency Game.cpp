int LargButMinFreq(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    int mini = 1e9;
    int ans;
    for (auto it : mp)
    {
        int ele = it.first;
        int count = it.second;
        if (mini > count)
        {
            mini = count;
            ans = ele;
        }
        else if (mini == count)
        {
            ans = max(ans, ele);
        }
    }
    return ans;
}