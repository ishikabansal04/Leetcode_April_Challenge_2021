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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(head->next == NULL && n==1) return NULL;
        ListNode* prev=head;
        ListNode* post=head;
        ListNode* pre=NULL;
        while(n>0 && post!=NULL){
            post = post->next;
            n--;
        }
        while(post!=NULL){
            pre = prev;
            prev = prev->next;
            post = post->next;
        }
        // if(prev==NULL) prev=head;
        if(prev==head) return head->next;
        // ListNode* temp = prev->next;
        pre->next = prev->next;
        delete(prev);
        return head;
    }
};
