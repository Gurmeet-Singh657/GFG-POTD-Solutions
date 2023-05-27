#include <bits/stdc++.h>
using namespace std;
Node *reverse(Node *head)
{
    Node *prev = NULL;
    while (head != NULL)
    {
        Node *ahead = head->next;
        head->next = prev;
        prev = head;
        head = ahead;
    }
    return prev;
}
struct Node *modifyTheList(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *fast = head, *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow;
    mid->next = reverse(mid->next);
    Node *first = head;
    Node *second = mid->next;
    while (second != NULL)
    {
        second->data = second->data - first->data;
        second = second->next;
        first = first->next;
    }
    mid->next = reverse(mid->next);
    return reverse(head);
}