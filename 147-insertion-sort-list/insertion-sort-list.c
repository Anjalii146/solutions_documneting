/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* insertionSortList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode *current = head;

    while(current != NULL)
    {
        struct ListNode *nextNode = current->next;

        struct ListNode *prev = &dummy;

        while(prev->next != NULL && prev->next->val < current->val)
        {
            prev = prev->next;
        }

        current->next = prev->next;
        prev->next = current;

        current = nextNode;
    }

    return dummy.next;
}