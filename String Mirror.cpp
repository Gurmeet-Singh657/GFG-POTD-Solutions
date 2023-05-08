#include<bits/stdc++.h>
using namespace std;
string stringMirror(string str)
{
    string curr = "";
    curr += str[0];
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] < str[i - 1])
        {
            curr += str[i];
        }
        else if (i > 1 && str[i] == str[i - 1])
        {
            curr += str[i];
        }
        else
        {
            break;
        }
    }
    string temp = curr;
    reverse(temp.begin(), temp.end());
    curr += temp;
    return curr;
}