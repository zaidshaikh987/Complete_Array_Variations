// - Check if Two Arrays are Equal (element frequency matching)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool areEqual(vector<int>& arr1, vector<int>& arr2) {
    if (arr1.size() != arr2.size()) return false;

    unordered_map<int, int> freq;
    for (int x : arr1) freq[x]++;
    
    for (int x : arr2) {
        if (freq.find(x) == freq.end() || freq[x] == 0) return false;
        freq[x]--;
    }
    
    return true;
}

int main() {
    vector<int> arr1 = {1, 2, 5, 4, 0};
    vector<int> arr2 = {2, 4, 5, 0, 1};
    
    cout << "Arrays are equal: " << (areEqual(arr1, arr2) ? "Yes" : "No") << endl;
    
    vector<int> arr3 = {1, 2, 5};
    vector<int> arr4 = {2, 4, 15};
    cout << "Arrays are equal: " << (areEqual(arr3, arr4) ? "Yes" : "No") << endl;
    
    return 0;
}
