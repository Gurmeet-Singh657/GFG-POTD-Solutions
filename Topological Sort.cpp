#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> indegree(V,0);
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        for(auto it:adj[i]) indegree[it]++;
    }
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty())
    {
        auto curr=q.front();
        ans.push_back(curr);
        q.pop();
        for(auto it:adj[curr])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return ans;
}