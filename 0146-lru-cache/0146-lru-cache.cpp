class LRUCache {
public:
    int cap_;
    
    struct LRU{
        int key;
        int val;
        LRU* prev;
        LRU* next;
    };
    unordered_map<int,LRU> map;
    LRU* head = nullptr;
    LRU* tail = nullptr;
    LRU* tar;
    int count= 0;
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        if(map.count(key)){
            moveBack(key);
            return map[key].val;
        }
        return -1;
        
    }
    void moveBack(int key){
        if(map.count(key)){
            auto node = &map[key];
            if(node == tail) return;
            //detach it and then put to the back

            LRU* n = node->next;
            LRU* p = node->prev;

            if(p) p->next = n;
            else{
                head = n;
            }
            n->prev = p;
            node->next = nullptr;
            node->prev = tail;

            tail->next = node;

            tail = node;
        }
        return;
    }

    void put(int key, int value) {
        if(map.count(key)){
            map[key].val = value;
            moveBack(key);
            return;
        }
        map[key] = LRU{key,value,nullptr, nullptr};
        auto node = &map[key];
        if(!head) head = node;
        if(tail != nullptr){
            node->prev = tail;
            tail->next = node;
        }
        tail = node;
        
        if(map.size() > cap_){
            int key = head->key;
            head = head->next;
            head->prev->next = nullptr;
            head->prev = nullptr;
            map.erase(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */