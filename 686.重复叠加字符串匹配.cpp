/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 */

// @lc code=start
class Solution
{
public:
    int repeatedStringMatch(const string &a, const string &b)
    {
        int m = a.size();
        int n = b.size();
        int st = 0;
        int ia;
        int ib;
        bool flag = false;
        while (st < m)
        {
            ia = st;
            while (ia < m && a[ia] != b[0])
                ++ia;
            if (st == ia)
                st++;
            else
                st = ia;
            ib = 0;
            while (ia < m && ib < n)
            {
                if (a[ia] == b[ib])
                {
                    ++ia;
                    ++ib;
                }
                else
                    break;
            }
            if (ib == n)
                return 1;
            if (ia != m)
            {
                continue;
            }
            int res = 1;
            ia = 0;
            flag = true;
            while (ib < n)
            {
                if (ia == 0)
                    res++;
                if (a[ia] != b[ib])
                {
                    flag = false;
                    break;
                }
                ib++;
                ia++;
                ia %= m;
            }
            if (!flag)
                continue;
            return res;
        }
        return -1;
    }
};
// @lc code=end
