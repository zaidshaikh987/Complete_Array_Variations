// - Majority Element II (> n/3 times)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method: Boyer-Moore Voting Algorithm for two candidates
vector<int> majorityElementII(vector<int>& nums) {
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
    
    for (int x : nums) {
        if (x == candidate1) {
            count1++;
        } else if (x == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = x;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = x;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Verify candidates
    count1 = count2 = 0;
    for (int x : nums) {
        if (x == candidate1) count1++;
        else if (x == candidate2) count2++;
    }

    vector<int> result;
    int n = nums.size();
    if (count1 > n / 3) result.push_back(candidate1);
    if (count2 > n / 3) result.push_back(candidate2);
    
    return result;
}

int main() {
    vector<int> nums = {3, 2, 3};
    vector<int> result = majorityElementII(nums);
    cout << "Majority Elements:> n/3: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> result2 = majorityElementII(nums2);
    cout << "Majority Elements:> n/3: ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    return 0;
}
