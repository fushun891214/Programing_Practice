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
    // 參數：vector 內每個元素都是指向 ListNode 的指標（即每條鏈結串列的頭）
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return NULL;
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;

        // Lambda 表達式，格式：[捕獲列表](參數列表) { 函式主體 }
        // []：捕獲列表為空，不需要外部變數
        // (ListNode *a, ListNode *b)：呼叫時傳入的參數
        // 
        // 比較器語義：回傳 true 表示 a 應該排在 b「後面」（優先級較低）
        // a->val > b->val 為 true 時，a 排後面 → 值小的優先 → 最小堆
        auto cmp = [](ListNode *a,ListNode *b){return a->val > b->val;};
        // 優先佇列（最小堆）
        // 模板參數：<元素類型, 底層容器, 比較器類型>
        // decltype(cmp)：自動推導 lambda 的類型
        // (cmp)：將比較器實例傳入建構子
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);

        for(ListNode *head: lists){
            if(head){
                pq.push(head);
            }
        }

        while(!pq.empty()){
            ListNode *n = pq.top();
            p->next = n;
            pq.pop();
            if(n->next){
                pq.push(n->next);
            }
            p = p->next;
        }
        return dummy->next;
    }
};