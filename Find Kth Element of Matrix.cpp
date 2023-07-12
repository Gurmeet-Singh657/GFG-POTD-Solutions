int findK(int a[MAX][MAX], int n, int m, int k)
{
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;
    int cnt = 0;
    while (top <= bottom && left <= right)
    {

        for (int i = left; i <= right; i++)
        {
            cnt++;
            if (cnt == k)
            {
                return a[top][i];
            }
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            cnt++;
            if (cnt == k)
            {
                return a[i][right];
            }
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cnt++;
                if (cnt == k)
                {
                    return a[bottom][i];
                }
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cnt++;
                if (cnt == k)
                {
                    return a[i][left];
                }
            }
            left++;
        }
    }
    return 0;
}