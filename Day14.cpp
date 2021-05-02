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
    ListNode* partition(ListNode* head, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq2;
        ListNode* ptr=head;
        int idx=0;
        while(ptr!=NULL){
            if(ptr->val < x){
                pq.push(make_pair(idx, ptr->val));
            }
            else{
                pq2.push(make_pair(idx, ptr->val));
            }
            idx++;
            ptr= ptr->next;
        }
        ptr = head;
        while(ptr!=NULL){
            while(pq.size()!=0){
                ptr->val = pq.top().second;
                pq.pop();
                ptr= ptr->next;
            }
            while(pq2.size()!=0){
                ptr->val = pq2.top().second;
                pq2.pop();
                ptr= ptr->next;
            }
        }
        return head;
    }
};
