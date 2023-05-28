#include<bits/stdc++.h>
using namespace std;
vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
vector<string> ans;
for(int i=0;i<N;i++)
{
    string curr=Dictionary[i];
    int ptr=0;
    for(int j=0;j<curr.size();j++)
    {
        if(isupper(curr[j]))
        {
            if(curr[j]==Pattern[ptr]) ptr++;
            else break;
        }
        if(ptr==Pattern.size()) break;
    }
    if(ptr==Pattern.size()) ans.push_back(curr);
}
if(ans.size()==0) ans.push_back("-1");
return ans;
}