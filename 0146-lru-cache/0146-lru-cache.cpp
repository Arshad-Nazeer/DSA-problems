class LRUCache {
public:
    struct Node{
        int key, value;
        Node* next, *prev;

        Node(int k, int val){
            this->key=k;
            this->value=val;
            this->next=NULL;
            this->prev=NULL;
        }
    };
    int capacity;
    Node* tail=NULL, *head=NULL;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        else{
            Node* temp=mp[key];
            if(head==temp) return temp->value; 
            temp->prev->next=temp->next;
            if(temp->next)  temp->next->prev=temp->prev;
            else tail=temp->prev; // if the key is at tail
            temp->next=head;
            temp->prev=NULL;
            head->prev=temp;
            head=temp;
            return temp->value;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            temp->value=value;
            if(head==temp) return;
            if(temp->next) temp->next->prev=temp->prev;
            else tail=temp->prev;
            temp->prev->next=temp->next;
            temp->next=head;
            head->prev=temp;
            head=temp;
        }else{
            if(mp.size()==capacity) {
                Node* temp=tail;
                if(tail->prev) {
                    tail->prev->next=NULL;
                    tail=tail->prev;
                }else{
                    head=NULL;
                    tail=NULL;
                }
                mp.erase(temp->key);
                delete temp;
            }
            Node* temp = new Node(key, value);
            mp[key]=temp;
            if(head==NULL && tail==NULL){
                head=temp;
                tail=temp;
            }else{
                temp->next=head;
                head->prev=temp;
                head=temp;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */