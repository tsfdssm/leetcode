/*
 * @lc app=leetcode.cn id=927 lang=cpp
 *
 * [927] 三等分
 */

// @lc code=start
class Solution
{
public:
    vector<int> threeEqualParts(vector<int> &arr)
    {
        int p1, p2, p3 = p2 = p1 = 0;
        int n = arr.size();
        int cnt = 0;
        vector<int> pos;
        for (int i = 0; i < n; ++i)
        {
            if (0 == arr[i])
                continue;
            ++cnt;
            pos.emplace_back(i);
        }
        if (0 == cnt)
            return {0, n - 1};
        if (cnt % 3 != 0)
            return {-1, -1};
        cnt /= 3;
        p1 = pos[pos.size() / 3 - 1];
        p2 = pos[pos.size() / 3 * 2 - 1];
        p3 = pos.back();
        int right0 = n - p3 - 1;
        for (int i = 1; i <= right0; ++i)
        {
            if (arr[p1 + i] == 1)
                return {-1, -1};
        }
        for (int i = 1; i <= right0; ++i)
        {
            if (arr[p2 + i] == 1)
                return {-1, -1};
        }
        int t1 = p1, t2 = p2, t3 = p3;
        for (int i = 0; i < cnt; --t1, --t2, --t3)
        {
            if (arr[t1] == arr[t2] && arr[t2] == arr[t3])
            {
                if (arr[t1] == 1)
                    ++i;
            }
            else
                return {-1, -1};
        }
        return {p1 + right0, p2 + right0 + 1};
    }
};
// @lc code=end
