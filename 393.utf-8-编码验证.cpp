/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

// @lc code=start
class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {

        int n = data.size();
        int index = 0;

        while (index < n)
        {
            while (index < n && (data[index] < 128))
                index++;
            if (index == n)
                break;
            int len = 1;
            while (len < 4 && ((data[index] & (1 << (7 - len))) != 0))
                ++len;
            if ((data[index] & (1 << (7 - len))) != 0)
                return false;
            if (index + len > n || len == 1)
                return false;
            for (int i = 1; i < len; ++i)
            {
                if ((0 == (data[i + index] & (1 << 7))) || (0 != (data[i + index] & (1 << 6))))
                    return false;
            }
            index += len;
        }
        return true;
    }
};
// @lc code=end
