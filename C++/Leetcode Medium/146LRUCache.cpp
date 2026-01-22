#include <unordered_map>
using namespace std;

class ListNodeE{
public:
    int val = -1;
    int key = -1;
    ListNodeE* next = nullptr;
    ListNodeE* prev = nullptr;
    ListNodeE(){}
};
class LRUCache {
public:
    ListNodeE* front;
    ListNodeE* back;
    unordered_map<int, ListNodeE*> map;
    int cap = 0;
    LRUCache(int capacity) {
        cap = capacity;
        front = new ListNodeE();
        back = new ListNodeE();
        front->next = back;
        back->prev = front;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) return -1;

        map[key]->prev->next = map[key]->next;
        map[key]->next->prev = map[key]->prev;

        back->prev->next = map[key];
        map[key]->prev = back->prev;
        map[key]->next = back;
        back->prev = map[key];

        return map[key]->val;
    }
    
    void put(int key, int value) {
        ListNodeE* node;
        if (map.find(key) != map.end()) {
            node = map[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        else node = new ListNodeE();
        node->key = key;
        node->val = value;
        
        back->prev->next = node;
        node->prev = back->prev;
        node->next = back;
        back->prev = node;

        map[key] = node;

        int n = map.size();
        if (n > cap) {
            ListNodeE* rem = front->next;
            rem->prev->next = rem->next;
            rem->next->prev = rem->prev;
            map.erase(rem->key);
            delete rem;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include<unordered_map>
using namespace std;
class ListNodeE {
public:
    int key;
    int val;
    ListNodeE* next;
    ListNodeE* prev;
    ListNodeE(int v, int k):val(v),key(k){}
};
class LRUCache {
public:
    int cap;
    ListNodeE* front;
    ListNodeE* back;
    unordered_map<int, ListNodeE*> map;
    LRUCache(int capacity) : cap(capacity) {
        front = new ListNodeE(-1, -1);
        back = new ListNodeE(-1,-1);
        front->next  = back;
        back->prev = front;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        else {
            int val = map[key]->val;
            removeNode(key);
            map[key] = new ListNodeE(val, key);
            pushToBackOfQueue(map[key]);
            return val;
        }
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) removeNode(key);
        map[key] = new ListNodeE(value, key);
        pushToBackOfQueue(map[key]);
        if (map.size() > cap) removeNode(front->next->key);
    }

private: 
    void removeNode(int key) {
        ListNodeE* node = map[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        map.erase(key);
        delete node;
    }
    void pushToBackOfQueue(ListNodeE* node) {
        back->prev->next = node;
        node->prev = back->prev;
        node->next = back;
        back->prev = node;
    }  
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */