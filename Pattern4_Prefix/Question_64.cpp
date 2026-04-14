// - Product of Array Except Self (No Division)

#include <iostream>
#include <vector>
using namespace std;

// LeetCode 238
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    // Left prefix products
    int leftProduct = 1;
    for (int i = 0; i < n; i++) {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }

    // Right suffix products (done on the fly)
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);

    cout << "Product of array except self: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
