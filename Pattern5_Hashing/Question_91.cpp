// - Intersection of Two Arrays (allowing duplicates)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> freq;
    for (int x : nums1) freq[x]++;
    
    vector<int> result;
    for (int x : nums2) {
        if (freq.count(x) && freq[x] > 0) {
            result.push_back(x);
            freq[x]--;
        }
    }
    
    return result;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = intersect(nums1, nums2);
    
    cout << "Intersection: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    
    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};
    vector<int> result2 = intersect(nums3, nums4);
    cout << "Intersection: ";
    for (int x : result2) cout << x << " ";
    cout << endl;
    
    return 0;
}
