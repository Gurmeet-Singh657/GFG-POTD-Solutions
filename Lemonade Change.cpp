bool lemonadeChange(int N, vector<int> &bills) {
    int count5=0,count10=0,count20=0;
    for(int i=0;i<N;i++)
    {
        if(bills[i]==5) // Don't give back anything
        {
            count5++; // Just take 5 in your pocket
        }
        else if(bills[i]==10) // You can only give back 5
        {
            if(count5==0) return false; // if 5 is not available to give back, return false
            count5--; // if available, then give 5 to customer
            count10++; // Take 10 from Him
        }
        else if(bills[i]==20) // You can only give back (5,5 and 5) OR (10 and 5)
        {
            if(count10>0 && count5>0) count10--,count5--; // if 10 is available & 5 is available
            else if(count5>=3) count5-=3; // if three 5 coins are available
            else return false; // Otherwise no combination possible
            
            count20++; // If possible take 20 in your pocket
        }
    }
    return true; // if all bills possible , return true
}