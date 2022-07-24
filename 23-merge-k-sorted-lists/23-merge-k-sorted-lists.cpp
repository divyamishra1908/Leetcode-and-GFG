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
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i:lists){
        ListNode* temp = i;
        while(temp != NULL){
            pq.push(temp->val);
            temp = temp->next;
        }            
    }
    ListNode* ans = new ListNode(0);
    ListNode* ptr = ans;
    while(!pq.empty()){
        ListNode* temp = new ListNode(pq.top());
        ptr->next = temp;
        ptr = ptr->next;
        pq.pop();
    }
    return ans->next;        
}
};