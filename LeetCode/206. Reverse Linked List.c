/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    struct ListNode *nxt = head->next;
    while(cur != NULL){
        cur->next = pre;
        pre = cur;
        cur = nxt;
        if(nxt != NULL){
            nxt = nxt->next;
        }
    }
    return pre;
}

struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode *last = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}