/*
 * @lc app=leetcode id=2463 lang=cpp
 *
 * [2463] Minimum Total Distance Traveled
 */

// @lc code=start
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // 扁平化 factory 陣列，將 limit 為 n 的 factory 轉換成 n 個 limit 為 1 的 factories
        vector<int> facPos;
        for (int i = 0; i < factory.size(); ++i) {
            for (int j = 0; j < factory[i][1]; ++j) {
                facPos.push_back(factory[i][0]);
            }
        }

        int m = facPos.size(), n = robot.size();
        // 需考慮 0~m 個 factory 與 0~n 個 robot，故dp的大小需為 (m+1)*(n+1)
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 1e15));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 0;  // 沒有 robot 時，距離為0

            /* robot 比 factory 多時，距離為無限大 (此行可省略)
            for (int j = i + 1; j <= n; ++j) dp[i][j] = 1e15;
            */
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > i) continue;  // robot 比 factory 多

                // 考慮第 i 個 factory 修理第 j 個 robot 與否
                // 第 i (j) 個 factory (robot) 在陣列的第 i-1 (j-1) 格
                // 改成 abs((long long)facPos[i-1] - robot[j-1]) 可進一步防止溢位風險
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(facPos[i-1] - robot[j-1]));
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

