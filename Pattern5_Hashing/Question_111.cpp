// - Minimum Window Substring (Hashing + Sliding Window)

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// Find the smallest substring of 's' that contains all characters of 't'.
string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    unordered_map<char, int> targetFreq;
    for (char c : t) targetFreq[c]++;

    unordered_map<char, int> windowFreq;
    int left = 0, minLen = INT_MAX, startIdx = -1;
    int required = targetFreq.size();
    int formed = 0;

    for (int right = 0; right < s.length(); right++) {
        char c = s[right];
        windowFreq[c]++;

        if (targetFreq.count(c) && windowFreq[c] == targetFreq[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            c = s[left];

            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIdx = left;
            }

            windowFreq[c]--;
            if (targetFreq.count(c) && windowFreq[c] < targetFreq[c]) {
                formed--;
            }
            left++;
        }
    }

    return startIdx == -1 ? "" : s.substr(startIdx, minLen);
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << "Minimum window substring of '" << s << "' containing '" << t << "': " << minWindow(s, t) << endl;
    return 0;
}
