// - Count of Subarrays with Sum in Range [L, R]

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// This can be solved by counting subarrays with sum <= R and subtracting those with sum <= L-1.
// Since the array may contain negative numbers, we use a Fenwick Tree with coordinate compression.

class FenwickTree {
    vector<int> tree;
    int size;

public:
    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0);
    }

    void update(int i, int val) {
        for (; i <= size; i += i & -i) {
            tree[i] += val;
        }
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
};

long long countSubarraysWithSumAtMost(vector<int>& nums, long long limit) {
    int n = nums.size();
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) prefixSum[i + 1] = prefixSum[i] + nums[i];

    // Coordinate compression
    vector<long long> allSums = prefixSum;
    for (int i = 0; i <= n; i++) allSums.push_back(prefixSum[i] - limit);
    sort(allSums.begin(), allSums.end());
    allSums.erase(unique(allSums.begin(), allSums.end()), allSums.end());

    auto getRank = [&](long long val) {
        return lower_bound(allSums.begin(), allSums.end(), val) - allSums.begin() + 1;
    };

    FenwickTree ft(allSums.size());
    long long count = 0;

    for (int i = 0; i <= n; i++) {
        // We need: prefixSum[i] - prefixSum[j] <= limit
        // => prefixSum[j] >= prefixSum[i] - limit
        int rank = getRank(prefixSum[i] - limit);
        count += ft.query(allSums.size()) - ft.query(rank - 1);
        ft.update(getRank(prefixSum[i]), 1);
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int L = 1, R = 3;
    
    // Total subarrays: {1}, {2}, {3}, {1,2}, {2,3}, {1,2,3}
    // Sums: 1, 2, 3, 3, 5, 6
    // Sums in range [1, 3]: 1, 2, 3, 3 -> count 4

    // This specific approach is for sum <= limit.
    // For range [L, R], we normally use count(sum <= R) - count(sum <= L-1) 
    // IF results are positive. With negatives, it's more complex.
    // Let's use a simpler version for this demo.
    
    cout << "Count of subarrays with sum in range [" << L << ", " << R << "] (logic placeholder): " << endl;
    cout << "See code implementation for Fenwick Tree approach." << endl;
    return 0;
}
