void quickSort(int arr[], int low, int high)
{
    if(low>=high) return;
    int p=partition(arr,low,high);
    quickSort(arr,low,p-1);
    quickSort(arr,p+1,high);
}

public:
int partition (int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low,j=low;
    while(j<=high)
    {
        if(arr[j]<pivot)
        {
            swap(arr[j],arr[i]);
            i++;
        }
        j++;
    }
    swap(arr[i],arr[high]);
    return i;
}