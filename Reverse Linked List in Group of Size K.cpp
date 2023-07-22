struct node *reverse(struct node *head, int k)
{
    bool firstpass = true;
    node *prevfirst = NULL;
    node *curr = head;
    while (curr != NULL)
    {
        node *first = curr, *prev = NULL;
        int count = 0;
        while (count < k && curr != NULL)
        {
            node *ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
            count++;
        }
        if (firstpass == true)
        {
            head = prev;
            firstpass = false;
        }
        else
        {
            prevfirst->next = prev;
        }
        prevfirst = first;
    }
    return head;
}