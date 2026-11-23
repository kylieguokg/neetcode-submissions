class LRUCache {
private:
    struct Node {
        int key = 0;
        int value = 0;
        Node* next = nullptr;
        Node* prev = nullptr;

        Node(int k, int v) : key(k), value(v) {}
    };

    unordered_map<int, Node*> cache;
    Node* mru = nullptr;
    Node* lru = nullptr;
    int capacity;
    int count = 0;

    void updateMru(Node* node){
        if (node == mru){
            return;
        }

        // detach node from current position
        if (node->prev){
            node->prev->next = node->next;
        }

        if (node->next){
            node->next->prev = node->prev;
        } else {
            // Node was the LRU
            lru = node->prev;
        }

        addMru(node);
    }

    void addMru(Node* node){
        node->prev = nullptr;
        node->next = mru;

        if (mru){
            mru->prev = node;
        }
        mru = node;

        if (!lru){
            lru = node;
        }
    }

    void removeLru(){
        if (!lru){
            return;
        }
        cache.erase(lru->key);

        Node* newLru = lru->prev;
        if (newLru){
            newLru->next = nullptr;
        } else {
            mru = nullptr;
        }
        delete lru;
        lru = newLru;
    }

public:

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()){
            return -1;
        }
        Node* node = it->second;
        updateMru(node);
        return node->value;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        Node* node;
        if (it == cache.end()){

            if (count + 1 > capacity){
                // remove lru
                removeLru();
                count--;
            }

            node = new Node(key, value);
            addMru(node);
            count++;
        } else {
            node = it->second;
            updateMru(node);
            node->value = value;
        }
        cache[key] = node;
    }
};
