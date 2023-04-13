#include<bits/stdc++.h>
using namespace std;
int finLength(int N, vector<int> color, vector<int> radius)
{
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        if (!st.empty())
        {
            int prev = st.top(); // topmost index
            if (color[prev] == color[i] && radius[prev] == radius[i])
                st.pop();
            else
                st.push(i);
        }
        else
            st.push(i);
    }
    return st.size();
}