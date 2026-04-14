// - Find the Most Frequent Element

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int mostFrequent(vector<int>& nums) {
    if (nums.empty()) return -1;
    
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;
    
    int result = nums[0];
    int maxFreq = 0;
    
    for (auto const& [key, val] : freq) {
        if (val > maxFreq) {
            maxFreq = val;
            result = key;
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 3, 2, 1, 4, 1};
    cout << "Most frequent element: " << mostFrequent(nums) << endl;
    return 0;
}
