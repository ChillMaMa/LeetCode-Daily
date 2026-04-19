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

/* Naive Approach

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int offset = 0;
        bool leftBound = false;
        bool rightBound = false;
        
        while(true) {
            if(!leftBound && nums[start - offset] == target) {
                return offset;
            }
            else if((start - offset) == 0) {
                leftBound = true;
            }

            if(!rightBound && nums[start + offset] == target) {
                return offset;
            }
            else if((start + offset) == nums.size() - 1) {
                rightBound = true;
            }

            offset++;
        }
    }
};

*/
// @lc code=end