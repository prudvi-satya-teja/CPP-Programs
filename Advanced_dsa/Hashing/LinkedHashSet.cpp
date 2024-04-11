#include<bits/stdc++.h>

using namespace std;

template<typename T>
class OrderedSet {
private:
    std::set<T> elements;
    std::vector<T> insertionOrder;

public:
    void insert(const T& value) {
        // Insert into the set only if it's not already present
        if (elements.insert(value).second) {
            insertionOrder.push_back(value);
        }
    }

    // Iterate over elements in insertion order
    void iterateInOrder() const {
        for (const auto& element : insertionOrder) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    OrderedSet<int> orderedSet;

    // Insert elements
    orderedSet.insert(5);
    orderedSet.insert(2);
    orderedSet.insert(8);
    orderedSet.insert(2); // This will not be inserted since 2 is already present

    // Iterate over elements in insertion order
    orderedSet.iterateInOrder();


    unordered_set<int> cities;

    cities.insert(5);
    cities.insert(2);
    cities.insert(8);
    cities.insert(2);

    for(int i: cities) {
        cout<<i <<endl;
    }

    return 0;
}
