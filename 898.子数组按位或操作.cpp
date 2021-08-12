/*
 * @lc app=leetcode.cn id=898 lang=cpp
 *
 * [898] 子数组按位或操作
 */

// @lc code=start
class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        set<int> res;
        set<int> cur;
        cur.insert(arr[0]);
        res.insert(arr[0]);
        int n = arr.size();

        for (int i = 1; i < n; ++i)
        {
            set<int> cur2;
            cur2.insert(arr[i]);
            for (int num : cur)
                cur2.insert(num | arr[i]);
            res.insert(cur2.begin(), cur2.end());
            cur = move(cur2);
        }
        return res.size();
    }
};
// @lc code=end
