#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
    };

    node* head; // Dummy head of the doubly linked list
    node* tail; // Dummy tail of the doubly linked list

    int cap; // Capacity of the cache
    unordered_map<int, node*> m; // Hash map for quick access to nodes

    // Constructor to initialize the LRU Cache
    LRUCache(int capacity) : cap(capacity) {
        head = new node(-1, -1); // Dummy head node
        tail = new node(-1, -1); // Dummy tail node
        head->next = tail; // Connect dummy head to dummy tail
        tail->prev = head; // Connect dummy tail to dummy head
    }

    // Add a node right after the head
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    // Remove a node from the doubly linked list
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    // Get the value of the key if it exists in the cache
    int get(int key) {
        if (m.find(key) != m.end()) {
            node* resnode = m[key];
            int res = resnode->val;
            m.erase(key); // Remove the node from the hash map
            deletenode(resnode); // Remove the node from the doubly linked list
            addnode(resnode); // Add the node to the front (most recently used)
            m[key] = head->next; // Update the hash map with the new node
            return res;
        }
        return -1; // Key not found
    }

    // Put a key-value pair into the cache
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            node* existingnode = m[key];
            m.erase(key); // Remove the old node from the hash map
            deletenode(existingnode); // Remove the old node from the doubly linked list
        }

        if (m.size() == cap) {
            m.erase(tail->prev->key); // Remove the least recently used node from the hash map
            deletenode(tail->prev); // Remove the least recently used node from the doubly linked list
        }

        addnode(new node(key, value)); // Add the new node to the front
        m[key] = head->next; // Update the hash map with the new node
    }
};

// Example usage
int main() {
    LRUCache* cache = new LRUCache(2); // Initialize LRU Cache with capacity 2
    cache->put(1, 1); // Cache is {1=1}
    cache->put(2, 2); // Cache is {1=1, 2=2}
    cout << cache->get(1) << endl; // return 1, Cache is {2=2, 1=1}
    cache->put(3, 3); // Evicts key 2, Cache is {1=1, 3=3}
    cout << cache->get(2) << endl; // returns -1 (not found)
    cache->put(4, 4); // Evicts key 1, Cache is {3=3, 4=4}
    cout << cache->get(1) << endl; // return -1 (not found)
    cout << cache->get(3) << endl; // return 3
    cout << cache->get(4) << endl; // return 4
    delete cache; // Clean up
    return 0;
}
