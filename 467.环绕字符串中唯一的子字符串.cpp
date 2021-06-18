/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

// @lc code=start
class Solution
{
public:
    int findSubstringInWraproundString(string p)
    {
        vector<int> mp(26, 0);
        int res = 0;
        int n = p.size();
        int len = 0;
        for (int i = 0; i < n; ++i)
        {
            if (0 != i && ((p[i] % 26) == ((p[i - 1] + 1) % 26)))
                ++len;
            else
                len = 1;
            if (mp[p[i] - 'a'] < len)
                mp[p[i] - 'a'] = len;
        }
        return accumulate(mp.begin(), mp.end(), 0);
        // unordered_set<string> st;
        // int res = 0;
        // int n = p.size();
        // for (int i = 0; i < n; ++i)
        // {
        //     if (!st.count(p.substr(i, 1)))
        //     {
        //         st.insert(p.substr(i, 1));
        //         res++;
        //     }
        //     for (int j = i + 1; j < n; ++j)
        //     {
        //         if (p[j] % 26 == (p[j - 1] + 1) % 26)
        //         {
        //             if (!st.count(p.substr(i, j - i + 1)))
        //             {
        //                 st.insert(p.substr(i, j - i + 1));
        //                 res++;
        //             }
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        // }
        // return res;
    }
};
// @lc code=end
