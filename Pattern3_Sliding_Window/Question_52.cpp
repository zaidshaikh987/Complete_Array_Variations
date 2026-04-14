// - Sliding Window Median (K-size Window Median)

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Using a multiset to maintain the window and find the median.
// For larger k, a more efficient approach (two heaps with balancing) is preferred.

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<double> medians;
    multiset<int> window;

    auto getMedian = [&]() {
        auto mid = window.begin();
        advance(mid, k / 2);
        if (k % 2 == 0) {
            auto prevMid = prev(mid);
            return ((double)*mid + *prevMid) / 2.0;
        } else {
            return (double)*mid;
        }
    };

    for (int i = 0; i < n; i++) {
        window.insert(nums[i]);

        if (window.size() > k) {
            window.erase(window.find(nums[i - k]));
        }

        if (window.size() == k) {
            medians.push_back(getMedian());
        }
    }

    return medians;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter window size k: ";
    cin >> k;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<double> result = medianSlidingWindow(nums, k);

    cout << "Medians in each sliding window: ";
    for (double d : result) cout << d << " ";
    cout << endl;

    return 0;
}
