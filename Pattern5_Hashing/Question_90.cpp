// - Count Occurrences of Each Element

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countOccurrences(vector<int>& arr) {
    // Using map instead of unordered_map to keep the output sorted by element
    map<int, int> freq;
    for (int x : arr) freq[x]++;

    cout << "Element counts:" << endl;
    for (auto const& [key, val] : freq) {
        cout << key << ": " << val << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    countOccurrences(arr);
    return 0;
}
