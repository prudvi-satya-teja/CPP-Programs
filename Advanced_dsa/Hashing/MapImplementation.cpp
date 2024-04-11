#include <iostream>  
#include <list>
#include <utility>
#include<vector>

template <typename Key, typename Value, typename Hash = std::hash<Key>>
class UnorderedMap {
private:
    using KeyValuePair = std::pair<Key, Value>;
    using Bucket = std::list<KeyValuePair>;
    using HashTable = std::vector<Bucket>;
    HashTable table;
    size_t numElements;
    static const size_t initialSize = 10; // Initial size of the hash table

    size_t hash(const Key& key) const {
        Hash hashFunction;
        return hashFunction(key) % table.size();
    }

public:
    UnorderedMap() : table(initialSize), numElements(0) {}

    void insert(const Key& key, const Value& value) {//o(LAMBDA) = o(1)
        size_t index = hash(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; // Update value if key already exists
                return;
            }
        }
        table[index].emplace_back(key, value);
        ++numElements;
    }

    Value* find(const Key& key) {
        size_t index = hash(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return &pair.second;
            }
        }
        return nullptr; // Key not found
    }

    size_t size() const {
        return numElements;
    }

    bool erase(const Key& key) {
        size_t index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                --numElements;
                return true;
            }
        }
        return false; // Key not found
    }

    Value& at(const Key& key) {
        Value* found = find(key);
        if (found == nullptr) {
            throw std::out_of_range("Key not found in map");
        }
        return *found;
    }
};

int main() {
    UnorderedMap<std::string, int> myMap;
    myMap.insert("One", 1);
    myMap.insert("Two", 2);
    myMap.insert("Three", 3);

    // Finding elements
    int* value = myMap.find("Two");
    if (value != nullptr) {
        std::cout << "Value of Two: " << *value << std::endl;
    } else {
        std::cout << "Key 'Two' not found." << std::endl;
    }

    // Erasing an element
    bool erased = myMap.erase("Three");
    if (erased) {
        std::cout << "Key 'Three' erased successfully." << std::endl;
    } else {
        std::cout << "Key 'Three' not found." << std::endl;
    }

    // Accessing elements using at
    try {
        int& val = myMap.at("One");
        std::cout << "Value of One (using at): " << val << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    // Size of the map
    std::cout << "Size of the map: " << myMap.size() << std::endl;

    return 0;
}
