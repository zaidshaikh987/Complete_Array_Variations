// - Longest Consecutive Sequence

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Find the length of the longest consecutive elements sequence.
// O(n) solution using a hash set.
int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    unordered_set<int> seen(nums.begin(), nums.end());
    int longestStreak = 0;

    for (int num : nums) {
        // Only start count if 'num' is the beginning of a sequence
        if (!seen.count(num - 1)) {
            int currentNum = num;
            int currentStreak = 1;

            while (seen.count(currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence length: " << longestConsecutive(nums) << endl; // {1, 2, 3, 4} -> 4
    return 0;
}
