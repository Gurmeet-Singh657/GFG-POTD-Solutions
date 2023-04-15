#include<bits/stdc++.h>
using namespace std;
int totalTime(int n, vector<int> &arr, vector<int> &time)
{
    int ans = 0;
    unordered_set<int> st; // store repeated elements
    st.insert(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (st.find(arr[i]) != st.end()) // repeated
        {
            ans += time[arr[i] - 1];
        }
        else // pick the element
        {
            ans++;
        }
        st.insert(arr[i]);
    }
    return ans;
}