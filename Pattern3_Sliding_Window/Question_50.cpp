// - Longest Repeating Character Replacement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k) {
    int n = s.length();
    vector<int> count(26, 0);
    int maxCount = 0; // max frequency of a single character in current window
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        count[s[right] - 'A']++;
        maxCount = max(maxCount, count[s[right] - 'A']);

        // Window length - maxCount = number of characters to replace
        // If this > k, shrink window
        while (right - left + 1 - maxCount > k) {
            count[s[left] - 'A']--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s;
    int k;
    cout << "Enter the string (uppercase letters): ";
    cin >> s;
    cout << "Enter k (max replacements allowed): ";
    cin >> k;

    int result = characterReplacement(s, k);
    cout << "Length of the longest repeating character replacement subarray is: " << result << endl;

    return 0;
}
