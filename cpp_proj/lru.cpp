#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    // Node structure representing a doubly linked list
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    // Pointers to the head and tail of the doubly linked list
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    // Cache capacity
    int cap;

    // Hashmap to store the keys and corresponding node pointers
    unordered_map<int, node*> m;

    // Constructor to initialize the cache with a given capacity
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Function to add a new node right after the head (most recently used)
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    // Function to delete a node from the linked list
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    // Function to get the value of a key from the cache
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }
        return -1; // Key does not exist
    }

    // Function to insert a key-value pair in the cache
    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key_, value));
        m[key_] = head->next;
    }
};

// Main function to demonstrate the LRU cache functionality
int main() {
    // Initialize the cache with a capacity of 2
    LRUCache lRUCache(2);

    // Perform put operations
    lRUCache.put(1, 1); // Cache is {1=1}
    lRUCache.put(2, 2); // Cache is {1=1, 2=2}

    // Perform get operations
    cout << lRUCache.get(1) << endl;    // Returns 1, Cache is {2=2, 1=1}
    
    lRUCache.put(3, 3);                 // LRU key was 2, evicts key 2, Cache is {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // Returns -1 (not found)

    lRUCache.put(4, 4);                 // LRU key was 1, evicts key 1, Cache is {3=3, 4=4}
    cout << lRUCache.get(1) << endl;    // Returns -1 (not found)
    cout << lRUCache.get(3) << endl;    // Returns 3, Cache is {4=4, 3=3}
    cout << lRUCache.get(4) << endl;    // Returns 4, Cache is {3=3, 4=4}

    return 0;
}
