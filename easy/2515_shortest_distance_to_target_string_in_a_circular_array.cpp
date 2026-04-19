/*
 * @lc app=leetcode id=2515 lang=cpp
 *
 * [2515] Shortest Distance to Target String in a Circular Array
 */

// @lc code=start
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int index = 0;
        int dist = INT_MAX;
        do {
            if (words[index] == target) {
                int distThisPass = min(abs(index-startIndex), ((int)words.size()-abs(index-startIndex)));
                dist = min(dist, distThisPass);
            }
                
        } while (++index < words.size());

        if (dist == INT_MAX)
            return -1;
        else
            return dist;
    }
};
// @lc code=end

