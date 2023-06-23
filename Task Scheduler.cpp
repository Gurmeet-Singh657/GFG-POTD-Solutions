int leastInterval(int N, int K, vector<char> &tasks)
{
    int freq[26] = {0};
    for (auto it : tasks)
        freq[it - 'A']++;
    int maxFreq = *max_element(freq, freq + 26);
    int lastExtras = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == maxFreq)
            lastExtras++;
    }
    return max(N, maxFreq + (maxFreq - 1) * K + (lastExtras - 1));
}