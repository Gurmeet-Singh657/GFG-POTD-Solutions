#include<bits/stdc++.h>
using namespace std;
int addMinChar(string str){    
        int n=str.length();
        int i=0,j=n-1;
        int ans=0;
        while(i<=j)
        {
            if(str[i]==str[j])
            {
                i++;
                j--;
            }
            else
            {
                ans++; // adding one character at the front
                i=0;
                j=n-1-ans;
            }
        }
        return ans;
    }