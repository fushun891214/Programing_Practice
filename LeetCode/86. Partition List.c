/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *dummy1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *dummy2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy1->next = NULL;
    dummy1->val = -1;
    dummy2->next = NULL;
    dummy2->val = -1;
    struct ListNode *p = head;
    struct ListNode *p1 = dummy1;
    struct ListNode *p2 = dummy2;
    while(p){
        if(p->val < x){
            p1->next = p;
            p1 = p1->next;
        }
        else{
            p2->next = p;
            p2 = p2->next;
        }
        struct ListNode *t = p->next;
        p->next = NULL;
        p = t;
    }
    p1->next = dummy2->next;
    return dummy1->next;
}