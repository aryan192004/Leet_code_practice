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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it : lists){
            ListNode *temp = it;
            while(temp != NULL){
                pq.push(temp->val);
                temp=temp->next;

            }
        }
        if (pq.empty()) {
            return NULL;
        }

        ListNode* head = new ListNode(pq.top());
        ListNode* temp = head;
        pq.pop();
        while(!pq.empty()){
            ListNode* node = new ListNode(pq.top());
            temp->next = node;
            pq.pop();
            temp=temp->next;
        }
        return head;
    }
};