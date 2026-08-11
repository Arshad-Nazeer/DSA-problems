/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // // HashMap approach TC:-O(n) SC:-O(n)
        // unordered_map<Node*, Node*> mp;
        // Node* temp=head;
        // while(temp!=NULL){
        //     Node* newNode = new Node(temp->val);
        //     mp[temp]=newNode;
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp!=NULL){
        //     Node* copyNode=mp[temp];
        //     copyNode->next=mp[temp->next]; 
        //     copyNode->random=mp[temp->random];
        //     temp=temp->next;
        // }
        // return mp[head];
        
        // optimal O(n)
        if(!head) return NULL;
        Node* temp=head;
        while(temp!=NULL){   // interweaving
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){   // setting randoms
            Node* copyNode=temp->next;
            if(temp->random) copyNode->random=temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        Node* copyHead=temp->next;
        while(temp!=NULL){   // setting next
            Node* copyNode=temp->next;
            temp->next=copyNode->next;
            if(copyNode->next) copyNode->next=copyNode->next->next;
            temp=temp->next;
        }
        return copyHead; 
    }
};