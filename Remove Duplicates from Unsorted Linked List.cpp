Node *removeDuplicates(Node *head)
{
    if (!head)
        return NULL;
    unordered_set<int> st;
    Node *curr = head;
    st.insert(head->data);
    while (curr->next != NULL)
    {
        if (st.find(curr->next->data) != st.end())
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
        st.insert(curr->data);
    }
    return head;
}