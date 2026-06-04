// A hashmap and hash set are the data sturctures that use hash functions to store and retrieve data efficiently.
// they do working in the o(1) time complexity for the average cases.

//.size() is used to return the size of hash set or hash map
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
    unordered_map<string , int> age_map;

    // 1. Insert key-value pairs
    age_map["Alice"] = 25;
    age_map["Bob"] = 30;
    age_map["haider"] = 8;

    age_map.insert({"charlie", 43}); // Another way to insert key-value pairs
    cout << age_map.count("haider") << endl; // Check if a key exists (returns 0 or 1)
    age_map.erase("Bob"); // Remove a key-value pair
    // age_map.clear(); // Clear all key-value pairs from the map
    // 2. Look up a value using the key
    string search_key = "haider";
    if (age_map.count(search_key)) {
        // Access value directly using []
        cout << search_key << "'s age is " << age_map[search_key] << ".\n";
    }

    return 0;
}