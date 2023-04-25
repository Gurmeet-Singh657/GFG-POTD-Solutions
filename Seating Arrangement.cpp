#include<bits/stdc++.h>
using namespace std;
bool is_possible_to_get_seats(int n, int m, vector<int> &seats)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        bool left = false, right = false;
        if (i == 0 || seats[i - 1] == 0)
            left = true;
        if (i == m - 1 || seats[i + 1] == 0)
            right = true;
        if (seats[i] == 0 && left && right)
        {
            count++;
            seats[i] = 1;
        }
    }
    return count >= n;
}