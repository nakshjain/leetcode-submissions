class LRUCache {
private:

    class Node{
        public:
        int val;
        int key;
        Node* next;
        Node* pre;

        Node(int key, int val){
            this->val=val;
            this->key=key;
            this->next=nullptr;
            this->pre=nullptr;
        }
    };

    Node* head=nullptr;
    Node* tail=nullptr;

    void insert(int key, int val){
        Node* node = new Node(key, val);
        if(!head){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            node->pre=tail;
            tail=tail->next;
        }
        mp[key]=node;
    }

    void remove(int key){
        Node* node = mp[key];
        Node* next= node->next;
        Node* pre= node->pre;
        if(!pre && !next){
            head=nullptr;
            tail=nullptr;
        } else if(!pre){
            head=next;
            head->pre=nullptr;
        } else if(!next) {
            tail=pre;
            pre->next=nullptr;
        } else {
            pre->next=next;
            next->pre=pre;
        }
        delete node;
        mp.erase(key);
    }

    int capacity=0;
    unordered_map<int, Node*> mp;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            int val = mp[key]->val;
            remove(key);
            insert(key, val);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            remove(key);
            insert(key, value);
        } else {
            if(mp.size()<capacity){
                insert(key, value);
            } else {
                int headKey = head->key;
                remove(headKey);
                insert(key, value);
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