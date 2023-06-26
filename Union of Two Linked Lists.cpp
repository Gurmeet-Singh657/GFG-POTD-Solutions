struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set<int> st;
    while(head1)
    {
        st.insert(head1->data);
        head1=head1->next;
    }
    while(head2)
    {
        st.insert(head2->data);
        head2=head2->next;
    }
    Node* head=new Node(-1);
    Node* tail=head;
    for(auto it:st)
    {
        tail->next=new Node(it);
        tail=tail->next;
    }
    return head->next;
}