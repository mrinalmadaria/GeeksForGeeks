//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
private:
    // Doubly Linked List to maintain order of usage
    std::list<int> dll; 
    
    // Hash map to store key -> (iterator to DLL, value)
    std::map<int, std::pair<std::list<int>::iterator, int>> mp; 
    
    // Cache capacity
    int cap; 

public:
    // Constructor to initialize the cache with given capacity
    LRUCache(int cap) {
        this->cap = cap;
    }

    // Utility function to move an accessed key to the front of the list
    void pushToFront(int key) {
        // Remove the key from its current position
        dll.erase(mp[key].first); 
        // Add it to the front of the list
        dll.push_front(key); 
        // Update the iterator in the map
        mp[key].first = dll.begin(); 
    }

    // Function to return value corresponding to the key
    int get(int key) {
        // If the key does not exist, return -1
        if (mp.find(key) == mp.end()) return -1;
        
        // Move the key to the front as it is accessed
        pushToFront(key);
        
        // Return the value associated with the key
        return mp[key].second; 
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            pushToFront(key); 
        } else {
            dll.push_front(key); 
            mp[key] = {dll.begin(), value}; 
            --cap; 
        }

        if (cap < 0) {
            int delKey = dll.back(); 
            dll.pop_back(); 
            mp.erase(delKey); 
            ++cap; 
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends