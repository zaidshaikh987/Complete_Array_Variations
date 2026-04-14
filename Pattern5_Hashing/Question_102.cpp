// - Group Anagrams

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Group strings that are anagrams of each other.
// Method: Sort each string to use as a key in a hash map.
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto const& [key, group] : groups) {
        result.push_back(group);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> resultedGroups = groupAnagrams(strs);

    cout << "Anagram Groups:" << endl;
    for (const auto& group : resultedGroups) {
        cout << "[ ";
        for (const string& s : group) cout << s << " ";
        cout << "]" << endl;
    }

    return 0;
}
