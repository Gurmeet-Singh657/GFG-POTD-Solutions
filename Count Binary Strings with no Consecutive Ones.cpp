#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/blog/entry/14516
#define mod (int)(1e9+7)
unordered_map<long,long> F;
long long f(long long n)
{
    if(F.find(n)!=F.end()) return F[n];
    long k=n/2;
    if(n%2==0) return F[n]=(f(k)*f(k)+f(k-1)*f(k-1))%mod;
    else return F[n]=(f(k)*f(k+1)+f(k-1)*f(k))%mod;
}
int countStrings(long long int N) {
    // Code here
    F[0]=F[1]=1;
    return f(N+1);
}