//
// Created by sky on 3/23/25.
//

/*
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 *
 * */
#include "util.h"

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        auto cp = nums;
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int ans = nums[i] + nums[j];
            if (ans == target) {
                vector<int> v;
                for (int k = 0; k < cp.size(); ++k) {
                    if (cp[k] == nums[i] || cp[k] == nums[j]) {
                        v.push_back(k);
                    }
                }
                return v;
            } else if (ans > target) {
                j--;
            } else {
                i++;
            }
        }

        throw runtime_error("unexcepted");
    }
};


void test() {
    auto s = Solution();
    {
        vector<int> nums{2, 7, 11, 15};
        int target = 9;
        auto ans = s.twoSum(nums, target);
        cout << "except 0, 1\n";
        cout << format("{}, {}", ans[0], ans[1]) << endl;
    }
    {
        vector<int> nums{3, 2, 4};
        int target = 6;
        auto ans = s.twoSum(nums, target);
        cout << "except 1, 2\n";
        cout << format("{}, {}", ans[0], ans[1]) << endl;
    }
    {
        vector<int> nums{3, 3};
        int target = 6;
        auto ans = s.twoSum(nums, target);
        cout << "except 0, 1\n";
        cout << format("{}, {}", ans[0], ans[1]) << endl;
    }
}