/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        ListNode *q = head;
        while(q != NULL){
            if((q->next != NULL) && (q->val == q->next->val)){
                while((q->next != NULL) && (q->val == q->next->val)){
                    q = q->next;
                }
                q = q->next;
                if(q == NULL){
                    p->next = NULL;
                }
            }
            else{
                p->next = q;
                p = p->next;
                q = q->next;
            }
        }
        return dummy->next;
    }
};

// 另一種解法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy1 = new ListNode(101);
        ListNode *dummy2 = new ListNode(101);
        ListNode *d1 = dummy1;
        ListNode *d2 = dummy2;
        ListNode *p = head;
        while(p != NULL){
            if((p->next != NULL) && (p->val == p->next->val) || (p->val == d1->val)){
                d1->next = p;
                d1 = d1->next;
            }
            else{
                d2->next = p;
                d2 = d2->next;
            }
            p = p->next;
            d1->next = NULL;
            d2->next = NULL;
        }
        return dummy2->next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 101;
    dummy->next = NULL;
    struct ListNode *p = dummy;
    struct ListNode *t = head;
    while(t != NULL){
        if((t->next != NULL) && (t->val == t->next->val)){
            while((t->next != NULL) && (t->val == t->next->val)){
                t = t->next;
            }
            t = t->next;
            if(t == NULL){
                p->next = NULL;
            }
        }else{
            p->next = t;
            p = p->next;
            t = t->next;
        }
    }
    return dummy->next;
}