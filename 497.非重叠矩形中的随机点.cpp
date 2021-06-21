/*
 * @lc app=leetcode.cn id=497 lang=cpp
 *
 * [497] 非重叠矩形中的随机点
 */

// @lc code=start
class Solution
{
public:
    int total = 0;
    vector<vector<int>> rects;
    vector<int> psum;
    Solution(vector<vector<int>> &rects)
    {
        this->rects = rects;
        for (const auto &rect : rects)
        {
            total += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            psum.push_back(total);
        }
    }
    vector<int> pick()
    {
        int target = random() % total;
        int l = 0, r = rects.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            // if (target >= psum[mid])
            //     l = mid + 1;
            // else
            //     r = mid;
            if (psum[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        auto &t = rects[l];
        int width = t[2] - t[0] + 1;
        int height = t[3] - t[1] + 1;
        int base = psum[l] - width * height;
        target -= base;
        return {t[0] + target % width, t[1] + target / width};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end
