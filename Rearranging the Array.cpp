void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] < 0)
        {
            temp.push_back(arr[i]);
            i++;
        }
        else if (arr[j] < 0)
        {
            temp.push_back(arr[j]);
            j++;
        }
        else
        {
            break;
        }
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= end)
        temp.push_back(arr[j++]);
    for (int i = start; i <= end; i++)
        arr[i] = temp[i - start];
}
void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
void Rearrange(int arr[], int n)
{
    mergeSort(arr, 0, n - 1);
}