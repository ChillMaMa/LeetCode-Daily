/*
 * @lc app=leetcode id=2833 lang=cpp
 *
 * [2833] Furthest Point From Origin
 */

// @lc code=start
class Solution {
   public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0, countUnderbar = 0;
        for (const char& s : moves) {
            if (s == 'L')
                ++countL;
            else if (s == 'R')
                --countL;
            else
                ++countUnderbar;
        }

        /* 註解的寫法效能較差
        // int countL = count(moves.begin(), moves.end(), 'L');
        // int countR = count(moves.begin(), moves.end(), 'R');
        // int countUnderbar = count(moves.begin(), moves.end(), '_');
        */

        return countUnderbar + abs(countL);
    }
};
// @lc code=end

