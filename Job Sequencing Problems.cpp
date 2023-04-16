#include<bits/stdc++.h>
using namespace std;
static bool cmp(Job& J1,Job& J2)
{
    return J1.profit>J2.profit;
}
//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) 
{ 
    // Sorting the Jobs on the basis of Profit in descending order
    // Maximize the Profit
    sort(arr,arr+n,cmp);
    bool Deadline[100001]={0};
    int count=0,profit=0;
    for(int i=0;i<n;i++)
    {
        int currdead=arr[i].dead;
        int currprofit=arr[i].profit;
        // Latest Deadline available
        // Smaller Deadline work should be done firstly
        while(currdead>=1 && Deadline[currdead]==1)
        {
            currdead--;
        }
        if(currdead>=1)
        {
            Deadline[currdead]=true;
            profit+=currprofit;
            count++;
        }
    }
    return {count,profit};
}