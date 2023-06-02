void DFS(int node,bool vis[],vector<vector<int>>& g,int& size)
{
    size++;
    vis[node]=true;
    for(auto it:g[node])
    {
        if(vis[it]) continue;
        DFS(it,vis,g,size);
    }
}
vector<int> prime;
void precompute(){
    vector<bool> isprime(1000001,1);
    isprime[0]=isprime[1]=0;
    for(int i=2;i<=1000000;i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            isprime[i]=true;
            for(int j=2*i;j<1000000;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
}
int helpSanta(int n, int m, vector<vector<int>> &g){
    int maxsize=0;
    bool vis[n]={0};
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            int size=0;
            DFS(i,vis,g,size);
            maxsize=max(maxsize,size);
        }
    }
    if(maxsize==1)
    {
        return -1;
    }
    return prime[maxsize-1];
}