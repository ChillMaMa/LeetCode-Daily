/*
 * @lc app=leetcode id=1855 lang=cpp
 *
 * [1855] Maximum Distance Between a Pair of Values
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        int j = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            j = max(j, i + maxDist + 1);  // Pruning
            while (j < nums2.size() && nums1[i] <= nums2[j]) {
                ++j;
            }

            int dist = j - 1 - i;
            maxDist = max(maxDist, dist);
        }
        return maxDist;
    }
};

/* Brute Force (TLE 23 / 32 testcases passed)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = nums2.size() - 1; j >= (i+maxDist+1); --j) {
                if (nums1[i] <= nums2[j]) {
                    maxDist = max(maxDist, j - i);
                }
            }
        }
        return maxDist;
    }
};
*/
// @lc code=end
