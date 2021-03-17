/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        while(x!=0)
        {
            if(res>INT32_MAX/10)
                return 0;
            if(res<INT32_MIN/10)
                return 0;

            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    //  int reverse(int x)
    // {
    //     long long tmp = abs(x);
    //     bool pos = x >= 0 ? true : false;
    //     string s = to_string(tmp);
    //     std::reverse(s.begin(), s.end());
    //     tmp = atoi(s.c_str());
    //     if (!pos)
    //         tmp = -tmp;

    //     if (tmp >= INT32_MAX||tmp <= INT32_MIN)
    //         return 0;
    //     return (int)tmp;
    // }
};
// @lc code=end
//  int reverse(int x)
//     {
//         long long tmp = abs(x);
//         bool pos = x >= 0 ? true : false;
//         string s = to_string(tmp);
//         std::reverse(s.begin(), s.end());
//         tmp = stoll(s);
//         if (!pos)
//             tmp = -tmp;

//         if (tmp > INT32_MAX||tmp < INT32_MIN)
//             return 0;
//         return (int)tmp;
//     }
int main()
{
    int x = -123;
    Solution a;
    cout << a.reverse(x);
}