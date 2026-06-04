#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    unordered_set<int> unique_numbers;

    // 1. Insert elements
    unique_numbers.insert(10);
    unique_numbers.insert(20);
    unique_numbers.insert(10); // Duplicate entry (ignored automatically)
    unique_numbers.erase(10); // Remove an element
    cout << unique_numbers.count(10) << endl; // Check if an element exists (returns 0 or 1)
    // unique_numbers.empty();
    // unique_numbers.clear(); // Clear all elements from the set
    // 2. Check if an element exists using .count()
    int target = 20;
    if (unique_numbers.count(target)) {
        cout << target << " exists in the set.\n"; // This will print
    }

    return 0;
}