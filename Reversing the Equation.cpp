string reverseEqn (string s)
{
    string temp="";
    int i=s.length()-1;
    while(i>=0)
    {
        if(isdigit(s[i]))
        {
            string curr="";
            while(i>=0 && isdigit(s[i]))
            {
                curr.push_back(s[i]);
                i--;
            }
            reverse(curr.begin(),curr.end());
            temp+=curr;
        }
        else
        {
            temp+=s[i];
            i--;
        }
    }
    return temp;
}