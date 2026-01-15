/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = NULL;
    struct ListNode *p = dummy;
    struct ListNode *p1 = list1;
    struct ListNode *p2 = list2;
    while(p1 && p2){
        if(p1->val < p2->val){
            p->next = p1;
            p1 = p1->next;
        }else{
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    while(p1){
        p->next = p1;
        p1 = p1->next;
        p = p->next;
    }
    while(p2){
        p->next = p2;
        p2 = p2->next;
        p = p->next;
    }
    return dummy->next;
}