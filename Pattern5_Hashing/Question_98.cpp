// - Top K Frequent Elements

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// Find the k most frequent elements in the array.
// Method: Min-heap with size k (O(n log k))
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;

    // Min-heap storing pairs of {frequency, element}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto const& [element, count] : freq) {
        minHeap.push({count, element});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    // Result is in ascending order of frequency, reverse to get descending if needed
    // reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}
