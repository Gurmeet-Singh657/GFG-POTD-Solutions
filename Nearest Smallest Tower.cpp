#include<bits/stdc++.h>
using namespace std;
vector<int> nearestSmallerTower(vector<int> arr)
{
    int n = arr.size();
    vector<int> prev, next;
    stack<int> st;
    // Find Prev Smaller Element
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            prev.push_back(-1);
        else
            prev.push_back(st.top());
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    // Find Next Smaller Element
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            next.push_back(-1);
        else
            next.push_back(st.top());
        st.push(i);
    }
    reverse(next.begin(), next.end());

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        // Neither left nor right
        if (prev[i] == -1 && next[i] == -1)
            ans.push_back(-1);
        else if (prev[i] == -1)
            ans.push_back(next[i]);
        else if (next[i] == -1)
            ans.push_back(prev[i]);
        else
        {
            if (i - prev[i] == next[i] - i)
            {
                if (arr[prev[i]] <= arr[next[i]])
                    ans.push_back(prev[i]);
                else
                    ans.push_back(next[i]);
            }
            else if (i - prev[i] < next[i] - i)
            {
                ans.push_back(prev[i]);
            }
            else
            {
                ans.push_back(next[i]);
            }
        }
    }
    return ans;
}