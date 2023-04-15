#include<bits/stdc++.h>
using namespace std;
long long solve(int N, vector<int> &A, vector<int> &B)
{
    sort(A.begin(), A.end()); // closer element should remain closer
    sort(B.begin(), B.end()); // Minimum opern
    vector<int> Aodds, Aevens, Bodds, Bevens;
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i++)
    {
        sum1 += A[i];
        sum2 += B[i];
        if (A[i] % 2 != 0)
            Aodds.push_back(A[i]);
        else
            Aevens.push_back(A[i]);
        if (B[i] % 2 != 0)
            Bodds.push_back(B[i]);
        else
            Bevens.push_back(B[i]);
    }
    // confirmation that A->B
    if (sum1 != sum2 || Aodds.size() != Bodds.size())
        return -1;

    long long ans = 0;
    for (int i = 0; i < Aodds.size(); i++)
    {
        ans += abs(Aodds[i] - Bodds[i]);
    }
    for (int i = 0; i < Aevens.size(); i++)
    {
        ans += abs(Aevens[i] - Bevens[i]);
    }
    return ans / 4;
}