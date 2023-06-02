int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
    reverse(S1.begin(),S1.end());
    reverse(S2.begin(),S2.end());
    reverse(S3.begin(),S3.end());
    int equalsum=0;
    int i=0,j=0,k=0;
    int sum1=0,sum2=0,sum3=0;
    while(i<N1 || j<N2 || k<N3)
    {
        if(sum1<=sum2 && sum1<=sum3)
        {
            if(i==N1) break;
            sum1+=S1[i];
            i++;
        }
        else if(sum2<=sum1 && sum2<=sum3)
        {
            if(j==N2) break;
            sum2+=S2[j];
            j++;
        }
        else 
        {
            if(k==N3) break;
            sum3+=S3[k];
            k++;
        }
        if(sum1==sum2 && sum2==sum3) equalsum=sum1;
    }
    return equalsum;
}