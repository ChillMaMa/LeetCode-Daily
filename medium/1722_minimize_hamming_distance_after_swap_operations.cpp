/*
 * @lc app=leetcode id=1722 lang=cpp
 *
 * [1722] Minimize Hamming Distance After Swap Operations
 */

// @lc code=start
struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // 初始化所有vertex的parent為自己
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);
        for (int i=0; i<allowedSwaps.size(); ++i) {
            dsu.unite(allowedSwaps[i][0], allowedSwaps[i][1]);
        }

        unordered_map<int,vector<int>> connectedMap;  // 連通元件
        for (int i=0; i<n; ++i) {
            connectedMap[dsu.find(i)].push_back(i);  // 相同root的index屬於同一個連通元件
        }

        int dist = n;
        for (const auto& kv : connectedMap) {  // 遍歷每個連通元件
            vector<int> neighbors = kv.second;
            vector<int> nums1, nums2;  // 紀錄(連通元件內)source、target對應的數字
            for (const int& i : neighbors) {
                nums1.push_back(source[i]);
                nums2.push_back(target[i]);
            }

            unordered_map<int, int> counts;
            for (int x : nums1) counts[x]++;  // 記錄(連通元件內)source的每個數字各出現幾次

            for (int x : nums2) {
                if (counts[x] > 0) {
                    --dist;
                    --counts[x]; // 消耗掉一個次數
                }
            }
        }
        return dist;
    }
};
// @lc code=end

