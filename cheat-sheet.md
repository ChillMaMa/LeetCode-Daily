// [Number Reversal]
    long long reverse(int n) {
        long long rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

// [Traverse a vector container]
    vector<int> nums;
    ...
    for (const int& n : nums) {
        
    }

// [Traverse connected components]
    unordered_map<int,vector<int>> connectedMap;
    for (const auto& [node, neighbors] : connectedMap) {
        // node 是 int (key)
        // neighbors 是 vector<int> (value)
    }
    for (const auto& kv : connectedMap) {
        int node = kv.first;                // 這裡拿到 Key
        vector<int> neighbors = kv.second;  // 這裡拿到 Value
    }

// [Disjoint Set Union]
    struct DSU {
        vector<int> parent;

        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0); // 初始化所有vertex的parent為自己
        }

        int find(int i) {
            if (parent[i] = i) return i;
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

// [Intersection of Two Arrays I]
    vector<int> nums1,nums2;
    ...
    // 若 s 存的是比較小的那個 vector，可以微幅提升效能
    unordered_set<int> s(nums1.begin(), nums1.end());
    int count = 0;
    for (int x : nums2) {
        if (s.erase(x)) {  // erase 會回傳是否刪除成功
            count++;
        }
    }
    return count;

// [Intersection of Two Arrays II]
    1. 雙指標法
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0, count = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                count++; // 找到一對，計數
                i++; j++; // 兩個都移動，消耗掉這對元素
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return count;
    2. Hash Table
        unordered_map<int, int> counts;
        for (int x : nums1) counts[x]++; // 記錄第一個陣列每個數字出現幾次

        int count = 0;
        for (int x : nums2) {
            if (counts[x] > 0) {
                count++;
                counts[x]--; // 消耗掉一個次數
            }
        }
        return count;