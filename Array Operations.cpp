#include<bits/stdc++.h>
using namespace std;
int arrayOperations(int n, vector<int> &arr) {
        int i=0;
        int count=0;
        while(i<n)
        {
            bool flag=false;
            while(i<n && arr[i]!=0)
            {
                flag=true;
                i++;
            }
            if(flag==true) // atleast one element is there
            {
                count++;
            }
            while(i<n && arr[i]==0)
            {
                i++;
            }
        }
        return count;
    }