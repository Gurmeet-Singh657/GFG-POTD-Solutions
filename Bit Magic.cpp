#include<bits/stdc++.h>
using namespace std;
int bitMagic(int n, vector<int> &arr) {
    int i=0,j=n-1;
    int countones=0;
    while(i<=j)
    {
        if(arr[i]!=arr[j]) countones++;
        i++;
        j--;
    }
    return (countones+1)/2;
}