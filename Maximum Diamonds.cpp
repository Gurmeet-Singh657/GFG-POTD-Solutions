long long maxDiamonds(int A[], int N, int K) {
    priority_queue<int> pq;
    for(int i=0;i<N;i++) pq.push(A[i]);
    
    long long ans=0;
    while(K--)
    {
        auto it=pq.top();
        pq.pop();
        ans+=it;
        pq.push(it/2);
    }
    return ans;
}