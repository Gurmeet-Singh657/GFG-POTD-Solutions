void update(int a[], int n, int updates[], int k)
{
    for(int i=0;i<k;i++)
    {
        int j=updates[i]-1;
        a[j]++;
    }
    for(int i=0;i<n;i++)
    {
        if(i>0) a[i]+=a[i-1];
    }
}