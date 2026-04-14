// - Find First Duplicate in Array

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Returns the first repeating element's value. 
// If no duplicate exists, returns -1.
int findFirstDuplicate(vector<int>& arr) {
    unordered_set<int> seen;
    for (int x : arr) {
        if (seen.count(x)) {
            return x;
        }
        seen.insert(x);
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 5, 3, 4, 3, 5, 6};
    int result = findFirstDuplicate(arr);
    if (result != -1) {
        cout << "First duplicate encountered: " << result << endl;
    } else {
        cout << "No duplicates found." << endl;
    }
    return 0;
}
