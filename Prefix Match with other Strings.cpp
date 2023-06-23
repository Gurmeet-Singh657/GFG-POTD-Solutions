int klengthpref(string arr[], int n, int k, string str)
{
    if (k > str.length())
        return 0;
    string temp = str.substr(0, k);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (temp == arr[i].substr(0, k))
        {
            count++;
        }
    }
    return count;
}