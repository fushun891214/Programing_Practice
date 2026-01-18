/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 尋找倒數第k個節點
// 倒數第k個節點位置在正數第n-k+1個位置
struct ListNode* findNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    for(int i = 0; i < n; i++){
        p1 = p1->next;
    }
    while(p1){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    dummy->val = -1;
    struct ListNode *p = dummy;
    p->next = head;
    // 尋找倒數第n+1個節點
    struct ListNode *node = findNthFromEnd(dummy, n + 1);
    node->next = node->next->next;
    return dummy->next;
}