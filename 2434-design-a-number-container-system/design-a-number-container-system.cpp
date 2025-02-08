#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
private:
    unordered_map<int, int> indexToValue;  
    unordered_map<int, set<int>> valueToIndices;  

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (indexToValue.find(index) != indexToValue.end()) {
            int oldValue = indexToValue[index];
            valueToIndices[oldValue].erase(index);

            if (valueToIndices[oldValue].empty()) {
                valueToIndices.erase(oldValue);
            }
        }
        indexToValue[index] = number;
        valueToIndices[number].insert(index);
    }
    
    int find(int number) {
        if (valueToIndices.find(number) != valueToIndices.end() && !valueToIndices[number].empty()) {
            return *valueToIndices[number].begin();  
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
