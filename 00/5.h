//
// Created by sky on 3/25/25.
//
/**
 *Given a string s, return the longest palindromic substring in s.

 Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

 Example 2:
Input: s = "cbbd"
Output: "bb"
 * */
#ifndef LEET_5_H
#define LEET_5_H

#include "util.h"

class Solution {
public:
    string longestPalindrome(string s) {
        string ret = "";
        for (int i = 0; i < s.size(); ++i) {
            int b = i;
            int e = i + 1;
            int ans = 0;
            auto fn = [&b, &e, &ans, &s]() -> string {
                while (b >= 0 && e < s.size()) {
                    if (s[b] != s[e]) {
                        break;
                    }
                    b--;
                    e++;
                    ans += 2;
                }
                return s.substr(b + 1, e - b - 1);
            };
            string m1 = fn();
            b = i - 1;
            e = i + 1;
            ans = 1;
            string m2 = fn();

            if (m1.size() > ret.size()) {
                ret = m1;
            }
            if (m2.size() > ret.size()) {
                ret = m2;
            }
        }
        return ret;
    }
};

void test() {
    auto s = Solution();
    {
        auto in = "babad";
        auto ans = s.longestPalindrome(in);
        cout << ans << " : except bab\n";
    }
    {
        auto in = "cbbd";
        auto ans = s.longestPalindrome(in);
        cout << ans << " : except bb\n";
    }
}

#endif //LEET_5_H
