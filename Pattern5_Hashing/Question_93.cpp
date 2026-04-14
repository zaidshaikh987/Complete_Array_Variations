// - Find the First Non-Repeating Element

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstNonRepeating(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;

    // We must traverse the array again to maintain the order
    for (int x : arr) {
        if (freq[x] == 1) {
            return x;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {9, 4, 9, 6, 7, 4};
    int result = firstNonRepeating(arr);
    if (result != -1) {
        cout << "First non-repeating element: " << result << endl;
    } else {
        cout << "All elements repeat." << endl;
    }
    return 0;
}
