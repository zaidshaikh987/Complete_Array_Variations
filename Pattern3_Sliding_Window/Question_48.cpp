// - Permutation in String

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) return false;

    vector<int> s1Freq(26, 0);
    vector<int> windowFreq(26, 0);

    for (int i = 0; i < s1.length(); i++) {
        s1Freq[s1[i] - 'a']++;
        windowFreq[s2[i] - 'a']++;
    }

    auto matches = [&]() {
        for (int i = 0; i < 26; i++) {
            if (s1Freq[i] != windowFreq[i]) return false;
        }
        return true;
    };

    for (int i = s1.length(); i < s2.length(); i++) {
        if (matches()) return true;

        // Move the window
        windowFreq[s2[i] - 'a']++;
        windowFreq[s2[i - s1.length()] - 'a']--;
    }

    return matches();
}

int main() {
    string s1, s2;
    cout << "Enter s1 (pattern): ";
    cin >> s1;
    cout << "Enter s2 (main string): ";
    cin >> s2;

    if (checkInclusion(s1, s2)) {
        cout << "s2 contains a permutation of s1." << endl;
    } else {
        cout << "s2 does not contain a permutation of s1." << endl;
    }

    return 0;
}
