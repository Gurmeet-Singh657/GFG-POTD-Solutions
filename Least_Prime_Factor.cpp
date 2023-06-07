vector<int> leastPrimeFactor(int n) {
    vector<int> prime(n+1,-1);
    prime[0]=0;
    prime[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==-1)
        {
            for(int j=i;j<=n;j+=i)
            {
                if(prime[j]==-1)
                    prime[j]=i;
            }
        }
    }
    return prime;
}