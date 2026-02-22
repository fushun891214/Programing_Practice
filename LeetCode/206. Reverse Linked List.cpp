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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *nxt = head->next;
        while(cur != NULL){
            cur->next = pre;
            pre = cur;
            cur = nxt;
            if(nxt){
                nxt = nxt->next;
            }
        }
        return pre;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};