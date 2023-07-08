bool findTriplets(int arr[], int n)
{ 
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++)
    {
        int start=i+1,end=n-1;
        while(start<end)
        {
            int curr=arr[i]+arr[start]+arr[end];
            if(curr<0)
            {
                start++;
            }
            else if(curr>0)
            {
                end--;
            }
            else if(curr==0)
            {
                return true;
            }
        }
    }
    return false;
}