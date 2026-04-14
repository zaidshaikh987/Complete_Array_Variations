// - Range Sum Queries (Mutable Array)

#include <iostream>
#include <vector>
using namespace std;

// This requires an efficient way to handle updates and queries.
// Fenwick Tree (Binary Indexed Tree) is a good choice for this.

class NumArray {
    vector<int> tree;
    vector<int> originalNums;
    int size;

public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        originalNums = nums;
        tree.resize(size + 1, 0);
        for (int i = 0; i < size; i++) {
            updateBIT(i + 1, nums[i]);
        }
    }

    void updateBIT(int i, int val) {
        for (; i <= size; i += i & -i) {
            tree[i] += val;
        }
    }

    void update(int index, int val) {
        int diff = val - originalNums[index];
        originalNums[index] = val;
        updateBIT(index + 1, diff);
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray na(nums);

    cout << "Sum [0, 2]: " << na.sumRange(0, 2) << endl; // 9
    na.update(1, 2);
    cout << "Sum [0, 2]: " << na.sumRange(0, 2) << endl; // 8
    
    return 0;
}
