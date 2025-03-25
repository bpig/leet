//
// Created by sky on 3/25/25.
//

#ifndef LEET_0003G_H
#define LEET_0003G_H
#include "util.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> m(128, -1);
        int left = 0;

        for (int right = 0; right < n; right++) {
            char c = s[right];
            if (m[c] >= left) {
                left = m[c] + 1;
            }
            m[c] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
#endif //LEET_0003G_H
