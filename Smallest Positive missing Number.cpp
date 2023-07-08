int missingNumber(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 1 && arr[i] <= n)
        {
            if (arr[arr[i] - 1] != arr[i])
            {
                swap(arr[i], arr[arr[i] - 1]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != arr[i])
            return i + 1;
    }
    return n + 1;
}