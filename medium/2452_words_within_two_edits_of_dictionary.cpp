/*
 * @lc app=leetcode id=2452 lang=cpp
 *
 * [2452] Words Within Two Edits of Dictionary
 */

// @lc code=start

// Brute Force
class Solution {
   public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries[0].size();
        vector<string> answer;

        for (const string& query : queries) {
            for (const string& s : dictionary) {
                int queriesCount = 2;
                for (int i = 0; i < n && queriesCount >= 0; ++i) {
                    if (s[i] != query[i])
                        --queriesCount;
                }
                if (queriesCount >= 0) {
                    answer.push_back(query);
                    break;
                }
            }
        }
        return answer;
    }
};
// @lc code=end

