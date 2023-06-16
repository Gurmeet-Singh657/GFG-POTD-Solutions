// Function to insert element into the queue
void insert(queue<int> &q, int k){
    q.push(k);
}

// Function to find frequency of an element
// return the frequency of k
int findFrequency(queue<int> &q, int k){
    queue<int> temp=q;
    int freq=0;
    while(temp.size())
    {
        if(temp.front()==k) freq++;
        temp.pop();
    }
    return freq;
}