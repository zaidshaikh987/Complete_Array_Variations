// - Check if an Array has Duplicate Elements

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool hasDuplicates(vector<int>& nums) {
    unordered_set<int> seen;
    for (int x : nums) {
        if (seen.count(x)) return true;
        seen.insert(x);
    }
    return false;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 3, 4};
    
    cout << "Array 1 has duplicates: " << (hasDuplicates(nums1) ? "Yes" : "No") << endl;
    cout << "Array 2 has duplicates: " << (hasDuplicates(nums2) ? "Yes" : "No") << endl;
    
    return 0;
}
