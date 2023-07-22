Node* segregate(Node *head) {
        
    Node* zeroDummy=new Node(0);
    Node* zeroHead=zeroDummy;
    Node* oneDummy=new Node(1);
    Node* oneHead=oneDummy;
    Node* twoDummy=new Node(2);
    Node* twoHead=twoDummy;
    
    Node* curr=head;
    while(curr)
    {
        if(curr->data==0) zeroDummy->next=curr,zeroDummy=zeroDummy->next;
        else if(curr->data==1) oneDummy->next=curr,oneDummy=oneDummy->next;
        else twoDummy->next=curr,twoDummy=twoDummy->next;
        curr=curr->next;
    }
    if(zeroHead->next)
    {
        if(oneHead->next)
        {
            zeroDummy->next=oneHead->next;
            oneDummy->next=twoHead->next;
        }
        else
        {
            zeroDummy->next=twoHead->next;
        }
        twoDummy->next=NULL;
        return zeroHead->next;
    }
    else
    {
        if(oneHead->next)
        {
            oneDummy->next=twoHead->next;
            twoDummy->next=NULL;
            return oneHead->next;
        }
        else
        {
            return twoHead->next;
            twoDummy->next=NULL;
        }
    }
    return NULL;
}