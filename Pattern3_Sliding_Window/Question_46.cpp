// - Sliding Window Minimum (O(n) using Deque)

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> minSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;
    deque<int> dq; // stores indices

    for (int i = 0; i < n; i++) {
        // Remove indices out of current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove elements larger than current element from back
        while (!dq.empty() && nums[dq.back()] >= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Standard window size reached
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
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

    vector<int> result = minSlidingWindow(nums, k);

    cout << "Minimums in each sliding window: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
