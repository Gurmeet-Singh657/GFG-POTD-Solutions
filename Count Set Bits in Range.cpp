int setSetBit(int x, int y, int l, int r){
    l--,r--;
    for(int i=l;i<=r;i++)
    {
        x|=(y&(1<<i));
    }
    return x;
}