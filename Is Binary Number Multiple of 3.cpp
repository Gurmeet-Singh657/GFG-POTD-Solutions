int isDivisible(string s)
{
    int Even = 0, Odd = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0 && s[i] == '1')
            Even++;
        if (i % 2 != 0 && s[i] == '1')
            Odd++;
    }
    // Even Even Even or Odd Odd Odd
    Even %= 3;
    Odd %= 3;
    // Even Odd will make pairs in themselves
    return Even == Odd;
}