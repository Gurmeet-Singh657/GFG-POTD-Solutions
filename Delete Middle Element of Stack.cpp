void deleteMid(stack<int>&s, int stSize)
{
    int target=(stSize/2);
    stack<int> tempSt;
    int count=target;
    while(count--)
    {
        tempSt.push(s.top());
        s.pop();
    }
    s.pop();
    while(target--)
    {
        s.push(tempSt.top());
        tempSt.pop();
    }
}