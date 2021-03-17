/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int myAtoi(string str)
    {
        bool ok = false;
        int i = 0,pos = 1;
        long long res = 0;
        for (; i < str.size(); i++)
        {
            if (str[i] == ' ')
                continue;
            if (str[i] == '+' || str[i] == '-' || str[i] >= '0' && str[i] <= '9')
            {
                ok = true;
                break;
            }
            else
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            return 0;
        if (str[i] == '-')
        {
            pos = -1;
            i++;
        }
        else if (str[i] == '+')
            i++;
        while (i < str.size())
        {
            if (str[i] < '0' || str[i] > '9')
                break;
           
            res *= 10;
            res += str[i] - '0';
            i++;
            if (pos * res > INT32_MAX)
                return INT32_MAX;
            if (pos * res < INT32_MIN)
                return INT32_MIN;
            }
        
        return pos*res;
    }
};
// @lc code=end
