/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
class Solution
{
public:
    static constexpr int target = 24;
    static constexpr double exp = 1e-6;
    static constexpr int add = 0, mul = 1, sub = 2, div = 3;
    bool judgePoint24(vector<int> &nums)
    {
        vector<double> l;
        for (const int &num : nums)
        {
            l.emplace_back(static_cast<double>(num));
        }
        return solve(l);
    }

    bool solve(vector<double> &l)
    {
        if (l.size() == 0)
        {
            return false;
        }
        if (l.size() == 1)
        {
            return fabs(l[0] - target) < exp;
        }
        int size = l.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i != j)
                {
                    vector<double> list2 = vector<double>();
                    for (int k = 0; k < size; k++)
                    {
                        if (k != i && k != j)
                        {
                            list2.emplace_back(l[k]);
                        }
                    }
                    for (int k = 0; k < 4; k++)
                    {
                        if (k < 2 && i > j)
                        {
                            continue;
                        }
                        if (k == add)
                        {
                            list2.emplace_back(l[i] + l[j]);
                        }
                        else if (k == mul)
                        {
                            list2.emplace_back(l[i] * l[j]);
                        }
                        else if (k == sub)
                        {
                            list2.emplace_back(l[i] - l[j]);
                        }
                        else if (k == div)
                        {
                            if (fabs(l[j]) < exp)
                            {
                                continue;
                            }
                            list2.emplace_back(l[i] / l[j]);
                        }
                        if (solve(list2))
                        {
                            return true;
                        }
                        list2.pop_back();
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
