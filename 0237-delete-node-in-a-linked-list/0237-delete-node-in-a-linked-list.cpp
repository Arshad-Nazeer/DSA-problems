/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // //brute
        // ListNode* prev=NULL;
        // while(node->next!=NULL){
        //     prev=node;
        //     node->val=node->next->val;
        //     node=node->next;
        // }
        // delete(node);
        // prev->next=NULL;

        //optimal
        ListNode* temp=node->next;
        node->val=temp->val;
        node->next=temp->next;
        delete temp;
    }
};