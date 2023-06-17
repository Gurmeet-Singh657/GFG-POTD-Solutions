int distributeTicket(int N, int K)
{
    int i = 1, j = N;
    int shift = K - 1;
    while (i + shift < j - shift)
    {
        i += K;
        j -= K;
    }
    // When all are completed
    if (i > j)
        return i;
    // In case when first i's are removed and they were equal to K
    // No one left
    if (i + shift >= j)
        return j;
    // In case when first i's are taken & some j's left
    return i + K;
}