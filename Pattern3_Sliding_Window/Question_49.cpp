// - Count of Anagrams in String

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int countAnagrams(string text, string pattern) {
    int n = text.length();
    int k = pattern.length();
    if (k > n) return 0;

    unordered_map<char, int> patternFreq;
    for (char c : pattern) patternFreq[c]++;

    unordered_map<char, int> windowFreq;
    for (int i = 0; i < k; i++) windowFreq[text[i]]++;

    int count = 0;
    
    auto isAnagram = [&]() {
        if (windowFreq.size() != patternFreq.size()) return false;
        for (auto const& [key, val] : patternFreq) {
            if (windowFreq[key] != val) return false;
        }
        return true;
    };

    if (isAnagram()) count++;

    for (int i = k; i < n; i++) {
        windowFreq[text[i]]++;
        windowFreq[text[i - k]]--;
        if (windowFreq[text[i - k]] == 0) {
            windowFreq.erase(text[i - k]);
        }

        if (isAnagram()) count++;
    }

    return count;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern (anagram to search for): ";
    cin >> pattern;

    int result = countAnagrams(text, pattern);
    cout << "Total count of anagrams of '" << pattern << "' in '" << text << "' is: " << result << endl;

    return 0;
}
