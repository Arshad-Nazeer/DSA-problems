/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // pointer splicing TC:- O()
        Node* curr=head, *temp, *child;
        while(curr!=NULL){
            if(curr->child!=NULL){
                child=curr->child;
                temp=curr->next;
                curr->next=child;
                child->prev=curr;
                while(child->next!=NULL) child=child->next;
                child->next=temp;
                if(temp) temp->prev=child;
                curr->child=NULL;
                curr=curr->next;
                continue;
            }
            curr=curr->next;
        }
        return head;
    }
};