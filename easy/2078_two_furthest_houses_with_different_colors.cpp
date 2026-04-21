/*
 * @lc app=leetcode id=2078 lang=cpp
 *
 * [2078] Two Furthest Houses With Different Colors
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        for (int i=0; i<n; ++i) {
            if (colors[0] != colors[n-1-i]) return n-1-i;
            if (colors[n-1] != colors[i]) return n-1-i;
        }
        return 0;
    }
};

/* Naive Approach
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int leftEndMaxDist = 0;
        int rightEndMaxDist = 0;
        int n = colors.size();
        for (int i=1; i<n; ++i) {
            if (colors[0] != colors[i]) leftEndMaxDist = i;
            if (colors[n-1] != colors[n-1-i]) rightEndMaxDist = i;
        }

        return max(leftEndMaxDist, rightEndMaxDist);
    }
};
*/
// @lc code=end

