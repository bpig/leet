//
// Created by sky on 3/23/25.
//

#ifndef LEET_0001G_H
#define LEET_0001G_H

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int c = target - nums[i];
            if (map.count(c)) {
                return {map[c], i};
            }
            map[nums[i]] = i;
        }

        return {}; // No solution found
    }
};

#endif //LEET_0001G_H
