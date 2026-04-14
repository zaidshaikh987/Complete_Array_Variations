// - Count of Subarrays with At Most K Distinct Integers

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// The trick is: count(at most k) = sum over all endings 'right': (right - left + 1)
// where window [left, right] has at most k distinct elements.

long long countAtMostK(vector<int>& arr, int k) {
    int n = arr.size();
    if (k == 0) return 0;

    unordered_map<int, int> freq;
    int left = 0;
    long long count = 0;

    for (int right = 0; right < n; right++) {
        freq[arr[right]]++;

        while (freq.size() > k) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }
            left++;
        }

        // All subarrays ending at 'right' and starting between 'left' and 'right'
        // have at most k distinct elements.
        count += (right - left + 1);
    }

    return count;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long result = countAtMostK(arr, k);
    cout << "Count of subarrays with at most " << k << " distinct integers is: " << result << endl;

    return 0;
}
