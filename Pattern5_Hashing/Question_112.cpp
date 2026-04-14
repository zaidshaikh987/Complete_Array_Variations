// - Largest Subarray with Equal Number of 0s, 1s, and 2s

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

// Find the length of the longest subarray with an equal number of 0s, 1s, and 2s.
// Logic: (count1 - count0) and (count2 - count1) must be same at indices i and j.
int findMaxLengthEqual012(vector<int>& arr) {
    int n = arr.size();
    unordered_map<string, int> comboIdx;
    comboIdx["0#0"] = -1; // Base case

    int count0 = 0, count1 = 0, count2 = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
        else if (arr[i] == 2) count2++;

        string key = to_string(count1 - count0) + "#" + to_string(count2 - count1);

        if (comboIdx.count(key)) {
            maxLen = max(maxLen, i - comboIdx[key]);
        } else {
            comboIdx[key] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {0, 1, 0, 2, 0, 1, 2};
    cout << "Length of the longest subarray with equal 0s, 1s, and 2s: " << findMaxLengthEqual012(arr) << endl;
    return 0;
}
