/*
 * @lc app=leetcode id=3761 lang=cpp
 *
 * [3761] Minimum Absolute Distance Between Mirror Pairs
 */

// @lc code=start
class Solution {
   public:
    long long reverse(int n) {
        long long rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<long long, int> posMap;
        int minDist = INT_MAX;
        int n = nums.size();

        for (int i=0; i<n; ++i) {
            if (posMap.count(nums[i]))  // 若posMap存在某key值等於nums[i]，代表之前有某元素的reverse是nums[i]
                minDist = min(minDist, i - posMap[nums[i]]);  // posMap[nums[i]]是該元素的index(在i之前)

            long long reverseVal = reverse(nums[i]);
            posMap[reverseVal] = i;  // 保存當下元素的reverse，供未來參考
        }

        return (minDist == INT_MAX) ? -1 : minDist;
    }
};
// @lc code=end

