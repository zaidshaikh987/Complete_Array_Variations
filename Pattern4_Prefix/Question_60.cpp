// - Running Sum / Cumulative Sum

#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixSum(n);
    if (n == 0) return prefixSum;
    
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    return prefixSum;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = runningSum(nums);
    
    cout << "Running sum: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}
