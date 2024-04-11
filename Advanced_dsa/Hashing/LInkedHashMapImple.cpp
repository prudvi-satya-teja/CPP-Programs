#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> lruList;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1; // Key not found
        }

        // Move the accessed key to the front (most recently used)
        lruList.splice(lruList.begin(), lruList, it->second.second);

        return it->second.first; // Return the value
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            // Key already exists, update the value and move it to the front
            it->second.first = value;
            lruList.splice(lruList.begin(), lruList, it->second.second);
        } else {
            if (cache.size() >= capacity) {
                int leastUsed = lruList.back(); // Get the least recently used key
                lruList.pop_back(); // Remove it from the list
                cache.erase(leastUsed); // Erase it from the map
            }
            // Insert the new key-value pair and move it to the front
            lruList.push_front(key);
            cache[key] = {value, lruList.begin()};
        }
    }
};

int main() {
    // Example usage
    LRUCache cache(2); // Capacity is 2
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3); // evicts key 2
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4); // evicts key 1
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4
    return 0;
}
