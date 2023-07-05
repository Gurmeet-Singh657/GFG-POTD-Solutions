int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
{
    int i = 0, j = 0;
    long long pro = 1;
    int count = 0;
    while (i < n)
    {
        pro *= a[i];
        while (j <= i && pro >= k)
        {
            pro /= a[j];
            j++;
        }
        count += (i - j + 1);
        i++;
    }
    return count;
}