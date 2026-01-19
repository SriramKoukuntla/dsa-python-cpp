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
        ListNodeE* Node;
        if (map.find(key) != map.end()) extractNode(key);
        else Node = new ListNodeE(value, key);
        map[key] = Node;
        pushToBackOfQueue(Node);
        if (map.size() > cap) removeNode(front->next->key);
    }

private: 
    ListNodeE* extractNode(int key) {
        ListNodeE* node = map[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return node;
    }
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