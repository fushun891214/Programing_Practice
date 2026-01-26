/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *dummy1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *dummy2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy1->val = 101;
    dummy2->val = 101;
    dummy1->next = NULL;
    dummy2->next = NULL;
    struct ListNode *p = head;
    struct ListNode *dp1 = dummy1;
    struct ListNode *dp2 = dummy2;
    while(p != NULL){
        if((p->next != NULL) && (p->val == p->next->val) || (p->val == dp1->val)){
            dp1->next = p;
            dp1 = dp1->next;
        }
        else{
            dp2->next = p;
            dp2 = dp2->next;
        }
        p = p->next;
        dp1->next = NULL;
        dp2->next = NULL;
    }
    return dummy2->next;
}