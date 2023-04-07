#include<bits/stdc++.h>
using namespace std;

vector<int> makeBeautiful(vector<int> arr)
{
    stack<int> st;
    for (auto it : arr)
    {
        if (st.size() > 0)
        {
            if (st.top() >= 0 && it < 0)
                st.pop();
            else if (st.top() < 0 && it >= 0)
                st.pop();
            else
                st.push(it);
        }
        else
        {
            st.push(it);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}