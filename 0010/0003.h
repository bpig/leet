//
// Created by sky on 3/24/25.
//

#ifndef LEET_0003_H
#define LEET_0003_H

/* *
Given a string s, find the length of the longest substring without duplicate characters.
Example 1:

 Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * */

#include "util.h"

class Solution {
public:
    inline int get_max(char* m, int ans) {
        int sum = accumulate(
                m, m + 256, 0, [](int acc, char element) {
                    return acc + (element != -1 ? 1 : 0);
                });
        ans = sum > ans ? sum : ans;
        return ans;
    }
    int lengthOfLongestSubstring(string s) {
        char m[256];
        fill(m, m+256, -1);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i] - 'a';
            if (m[c] != -1) {
                ans = get_max(m, ans);
                for (int j = 0; j < 256; ++j) {
                    if (m[j] != -1 && m[j] < m[c]) {
                        m[j] = -1;
                    }
                }
            }
            m[c] = i;
        }
        ans = get_max(m, ans);
        return ans;
    }
};

void test() {
    auto s = Solution();
    {
        string input = "dvdf";
        auto ans = s.lengthOfLongestSubstring(input);
        cout << format("{}, {}, expect 3\n", input, ans);
    }
    {
        string input = "pwwkew";
        auto ans = s.lengthOfLongestSubstring(input);
        cout << format("{}, {}, expect 3\n", input, ans);
    }
    {
        string input = "abcabcbb";
        auto ans = s.lengthOfLongestSubstring(input);
        cout << format("{}, {}, expect 3\n", input, ans);
    }
    {
        string input = "bbbbb";
        auto ans = s.lengthOfLongestSubstring(input);
        cout << format("{}, {}, expect 1\n", input, ans);
    }
}
#endif //LEET_0003_H
