/*
 * @lc app=leetcode id=2615 lang=cpp
 *
 * [2615] Sum of Distances
 */

// @lc code=start
class Solution {
   public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> answer(n, 0);

        unordered_map<int, vector<int>> posMap;
        for (int i = 0; i < n; ++i) posMap[nums[i]].push_back(i);

        for (const auto& [val, indices] : posMap) {  // val用不到
            long long total = 0;
            for (int x : indices) total += x;  // 先算index總和

            long long preSum = 0;
            for (int i = 0; i < indices.size(); ++i) {
                long long cur = indices[i];
                long long postSum = total - preSum - cur;

                // i即為preCount
                int postCount = indices.size() - 1 - i;

                // 左邊貢獻 + 右邊貢獻
                answer[cur] = (cur * i - preSum) + (postSum - cur * postCount);

                preSum += cur;
            }
        }
        // answer陣列的求算順序並非循序而是依照posMap中key值的順序
        return answer;
    }
};

/* Brute Force (TLE 1065 / 1068 testcases passed)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> answer;
        answer.reserve(nums.size());

        unordered_map<int, vector<int>> posMap;
        for (int i = 0; i < nums.size(); ++i) {
            posMap[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); ++i) {
            long long sum = 0;
            for (const int& pos : posMap[nums[i]]) {
                sum += abs(i-pos);
            }
            answer.push_back(sum);
        }
        return answer;
    }
};
*/
// @lc code=end

