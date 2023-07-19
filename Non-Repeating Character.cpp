char nonrepeatingCharacter(string S)
{
    unordered_map<char, int> mp;
    for (auto it : S)
    {
        mp[it]++;
    }
    for (auto it : S)
    {
        if (mp[it] == 1)
            return it;
    }
    return '$';
}