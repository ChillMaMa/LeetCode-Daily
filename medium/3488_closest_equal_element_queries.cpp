/*
 * @lc app=leetcode id=3488 lang=cpp
 *
 * [3488] Closest Equal Element Queries
 */

// @lc code=start
class Solution {
   public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> posMap;

        // 每個數字出現的所有index存進map
        for (int i = 0; i < n; ++i) {
            posMap[nums[i]].push_back(i);
        }

        vector<int> answer;
        answer.reserve(queries.size());  // 預留空間優化
        
        for (int qIdx : queries) {
            int target = nums[qIdx];
            const vector<int>& indices = posMap[target];  // indices紀錄了所有target的位置

            // 如果只有自己
            if (indices.size() <= 1) {
                answer.push_back(-1);
                continue;
            }

            // 使用二分搜尋找到qIdx在indices中的位置
            auto it = lower_bound(indices.begin(), indices.end(), qIdx);  

            // 檢查indices中緊鄰qIdx的兩個位置與頭尾(處理環狀)
            vector<int> candidates;  // 候選

            // 找到後一個
            auto next_it = next(it);
            if (next_it == indices.end())  // indices.end()沒有data
                candidates.push_back(indices[0]);
            else
                candidates.push_back(*next_it);
            // 找到前一個
            if (it == indices.begin())
                candidates.push_back(indices.back());
            else
                candidates.push_back(*prev(it));
            /* 簡化版
            candidates.push_back(next(it) == indices.end() ? indices[0] : *next(it));
            candidates.push_back(it == indices.begin() ? indices.back() : *prev(it));
            */

            // 環狀結構要考慮 n - diff
            int res = INT_MAX;
            for (int p : candidates) {
                int diff = abs(p - qIdx);
                res = min(res, min(diff, n - diff));
            }

            answer.push_back(res);
        }
        return answer;
    }
};

/* Brute Force (TLE 609 / 614 testcases passed)
class Solution {
   public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> answer(queries.size());
        vector<bool> found(queries.size(), false);
        int n = nums.size();
        for (int i = 0; i < queries.size(); ++i) {
            int minDist = INT_MAX;
            int target = nums[queries[i]];

            for (int j = 1; j <= (nums.size() / 2); ++j) {
                if (nums[(queries[i] + j) % n] == target) {
                    minDist = j;

                    break;
                }
            }
            for (int j = 1; j <= (nums.size() / 2); ++j) {
                if (nums[(queries[i] - j + n) % n] == target) {
                    if (minDist > j) minDist = j;

                    break;
                }
            }
            if (minDist == INT_MAX)
                answer[i] = -1;
            else {
                answer[i] = minDist;
                found[i] = true;
            }
        }
        return answer;
    }
};
*/

// @lc code=end

