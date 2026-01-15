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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode *p = &dummy;
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        while(p1 && p2){
            if(p1->val < p2->val){
                p->next = p1;
                p1 = p1->next;
            }
            else{
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
        return dummy.next;
    }
};