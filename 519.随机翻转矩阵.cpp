/*
 * @lc app=leetcode.cn id=519 lang=cpp
 *
 * [519] 随机翻转矩阵
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, int> V;
    int nr, nc, rem;
    Solution(int n_rows, int n_cols)
    {
        nr = n_rows;
        nc = n_cols;
        rem = nc * nr;
    }

    vector<int> flip()
    {
        int r = random() % rem;
        --rem;
        int x = V.count(r) ? V[r] : V[r] = r;
        V[r] = V.count(rem) ? V[rem] : V[rem] = rem;
        return {x / nc, x % nc};
    }

    void reset()
    {
        V.clear();
        rem = nc * nr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end
