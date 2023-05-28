#include<bits/stdc++.h>
using namespace std;
int getNthFromLast(Node *head, int n)
{
    Node *fast = head;
    while (n > 0 && fast != NULL)
    {
        fast = fast->next;
        n--;
    }
    if (n > 0)
        return -1;

    Node *slow = head;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}