// - Subarray with Exactly K Different Integers

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Logic: exactly(k) = atMost(k) - atMost(k-1)

long long atMostK(vector<int>& arr, int k) {
    if (k < 0) return 0;
    int n = arr.size();
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

        count += (right - left + 1);
    }
    return count;
}

long long exactlyK(vector<int>& arr, int k) {
    return atMostK(arr, k) - atMostK(arr, k - 1);
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter target k (number of exactly distinct integers): ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long result = exactlyK(arr, k);
    cout << "Total subarrays with exactly " << k << " distinct integers: " << result << endl;

    return 0;
}
