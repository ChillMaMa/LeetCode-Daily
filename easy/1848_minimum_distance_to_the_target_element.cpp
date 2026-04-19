/*
 * @lc app=leetcode id=1848 lang=cpp
 *
 * [1848] Minimum Distance to the Target Element
 */

// @lc code=start
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int index = -1;
        int minDist = INT_MAX;
        while(++index < nums.size()) {
            if(nums[index] == target) {
                minDist = min(minDist, abs(index - start));
            }
        }
        return minDist;
    }
};
// @lc code=end