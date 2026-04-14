// - Count Distinct Elements in Every Window of Size K

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method: Sliding Window with Hashing
vector<int> countDistinctInWindow(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> result;
    if (k > n) return result;

    unordered_map<int, int> freq;
    // Initialize the first window
    for (int i = 0; i < k; i++) {
        freq[arr[i]]++;
    }
    result.push_back(freq.size());

    // Slide the window
    for (int i = k; i < n; i++) {
        // Remove the leftmost element
        int leftVal = arr[i - k];
        freq[leftVal]--;
        if (freq[leftVal] == 0) {
            freq.erase(leftVal);
        }

        // Add the new rightmost element
        freq[arr[i]]++;
        
        result.push_back(freq.size());
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    vector<int> result = countDistinctInWindow(arr, k);
    
    cout << "Distinct elements in every window of size " << k << ": ";
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}
