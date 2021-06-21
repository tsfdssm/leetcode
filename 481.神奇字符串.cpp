/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */

// @lc code=start
class Solution
{
public:
    int magicalString(int n)
    {
        vector<int> vec = {1, 2, 2};
        int head = 2;
        int num = 1;
        int res = 1;
        while (vec.size() < n)
        {
            for (int i = 0; i < vec[head]; ++i)
            {
                vec.push_back(num);
                if (vec.size() <= n && num == 1)
                    res++;
            }
            num ^= 3;
            ++head;
        }
        return res;
        // string s = "122";
        // int i = 2;
        // while (s.size() < n)
        //     s += string(s[i++] - '0', s.back() ^ 3);
        // return count(s.begin(), s.begin() + n, '1');
    }
};
// @lc code=end
