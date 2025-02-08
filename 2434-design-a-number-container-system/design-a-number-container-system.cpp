#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
private:
    unordered_map<int, int> indexToValue;  // {index -> number}
    unordered_map<int, set<int>> valueToIndices;  // {number -> sorted set of indices}

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // If index already has a value, remove it from the old value's set
        if (indexToValue.find(index) != indexToValue.end()) {
            int oldValue = indexToValue[index];
            valueToIndices[oldValue].erase(index);

            // If no indices left for oldValue, remove entry
            if (valueToIndices[oldValue].empty()) {
                valueToIndices.erase(oldValue);
            }
        }

        // Update mappings
        indexToValue[index] = number;
        valueToIndices[number].insert(index);
    }
    
    int find(int number) {
        // If number exists in valueToIndices, return the smallest index
        if (valueToIndices.find(number) != valueToIndices.end() && !valueToIndices[number].empty()) {
            return *valueToIndices[number].begin();  // Get the smallest index
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number);
 * int param_2 = obj->find(number);
 */
