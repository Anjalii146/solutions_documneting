/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int length = 0;
    struct ListNode *p = head;

    while (p != NULL) {
        length++;
        p = p->next;
    }
    
    if (n == length) {
        return head->next;
    }

    int pos = length - n - 1;
    p = head;

    for (int i = 0; i < pos; i++) {
        p = p->next;
    }

    struct ListNode *q = p->next;
    p->next = q->next;

    return head;
}