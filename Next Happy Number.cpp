bool isHappy(int n)
{
    if (n == 1 || n == 7)
        return true;
    else if (n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 8 || n == 9)
        return false;

    int sum = 0;
    while (n)
    {
        int rem = n % 10;
        sum += (rem * rem);
        n /= 10;
    }
    return isHappy(sum);
}
int nextHappy(int N)
{
    N++;
    while (true)
    {
        if (isHappy(N))
        {
            return N;
        }
        N++;
    }
    return -1;
}