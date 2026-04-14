// - Count Subarrays with All 1s (binary array)

#include <iostream>
#include <vector>
using namespace std;

// Logic: A sequence of N ones has N*(N+1)/2 subarrays
long long countSubarraysAllOnes(vector<int>& arr) {
    long long totalCount = 0;
    long long currentCount = 0;

    for (int x : arr) {
        if (x == 1) {
            currentCount++;
        } else {
            totalCount += (currentCount * (currentCount + 1)) / 2;
            currentCount = 0;
        }
    }
    totalCount += (currentCount * (currentCount + 1)) / 2;
    return totalCount;
}

int main() {
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    cout << "Count of subarrays with all 1s: " << countSubarraysAllOnes(arr) << endl;
    return 0;
}
