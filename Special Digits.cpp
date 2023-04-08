#include<bits/stdc++.h>
using namespace std;
#define mod (int)(1e9+7)
    int Fact[100001];
    int binExp(int n,int x)
    {
        int ans=1;
        while(x)
        {
            if(x&1) ans=(ans*1LL*n)%mod;
            n=(n*1LL*n)%mod;
            x>>=1;
        }
        return ans;
    }
    void CreateFactorial()
    {
        Fact[0]=1; 
        for(int i=1;i<=100000;i++)
        {
            Fact[i]=(i*1LL*Fact[i-1])%mod;
        }
    }
    int nCr(int N,int i)
    {
        // N!/i!*(N-i)!
        int numerator=Fact[N];
        int denominator=(Fact[i]*1LL*Fact[N-i])%mod;
        return (numerator *1LL* binExp(denominator,mod-2))%mod;
    }
    int bestNumbers(int N, int A, int B, int C, int D) {
        
        CreateFactorial();
        long long ans=0;
        for(int i=0;i<=N;i++)
        {
            // i-> Number of A's
            // N-i -> Number of B's
            int sum=i*A+(N-i)*B;
            bool best=true;
            while(sum>0)
            {
                int rem=sum%10;
                if(rem!=C && rem!=D) 
                {
                    best=false;
                    break;
                }
                sum/=10;
            }
            if(best)
            {
                ans=(ans+nCr(N,i)%mod)%mod;
            }
        }
        return ans;
    }