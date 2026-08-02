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
    // Node* dfs(Node* head){
    //     Node *curr=head, *tail=head;

    //     while(curr!=NULL){
    //         Node* next=curr->next;
    //         if(curr->child){
    //             Node* childHead=curr->child;
    //             Node* childTail=dfs(childHead);
    //             curr->next=childHead;
    //             childHead->prev=curr;
    //             curr->child=NULL;
    //             childTail->next=next;
    //             if(next) next->prev=childTail;

    //             tail=childTail;
    //             curr=childTail;
    //         }else tail=curr; // works at the end of DLL
    //         curr=curr->next;
    //     }
    //     return tail;
    // }

    Node* flatten(Node* head) {
        // // recursive DFS TC:-O(n) // recursion depth SC:-O(d)
        // if(!head) return NULL;
        // dfs(head);
        // return head;

        // stack
        if(!head) return NULL;
        stack<Node*> stk;
        Node *curr=head;
        
        while(curr){
            if(curr->child!=NULL){
                if(curr->next) stk.push(curr->next);

                curr->next=curr->child;
                curr->next->prev=curr;
                curr->child=NULL;
            }else if(curr->next==NULL && !stk.empty()){
                curr->next=stk.top();
                stk.pop();
                curr->next->prev=curr;
            }
            curr=curr->next;
        }
        return head;

        // // pointer splicing TC:- O()
        // Node* curr=head, *temp, *child;
        // while(curr!=NULL){
        //     if(curr->child!=NULL){
        //         child=curr->child;
        //         temp=curr->next;
        //         curr->next=child;
        //         child->prev=curr;
        //         while(child->next!=NULL) child=child->next;
        //         child->next=temp;
        //         if(temp) temp->prev=child;
        //         curr->child=NULL;
        //         curr=curr->next;
        //         continue;
        //     }
        //     curr=curr->next;
        // }
        // return head;
    }
};