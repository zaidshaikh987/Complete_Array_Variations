// - Find the First Repeating Element

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// The first repeating element is the one that appears first in the array
// and has at least one more occurrence later.
int firstRepeating(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;

    for (int x : arr) {
        if (freq[x] > 1) {
            return x;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 5, 3, 4, 3, 5, 6};
    int result = firstRepeating(arr);
    if (result != -1) {
        cout << "First repeating element (by first appearance): " << result << endl;
    } else {
        cout << "No repeating elements found." << endl;
    }
    return 0;
}
