/*
 * @lc app=leetcode.cn id=1012 lang=cpp
 *
 * [1012] 至少有 1 位重复的数字
 */

// @lc code=start
class Solution
{
public:
    int fact(int n)
    {
        if (n == 1 || n == 0)
            return 1;
        return n * fact(n - 1);
    }
    int A(int m, int n)
    {
        return fact(n) / fact(n - m);
    }
    int F(int n) //不重复的个数
    {
        vector<int> digits; //存储 n的每一个位上的数字
        while (n > 0)
        {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end()); //1234   存储了1 2 3 4
        int k = digits.size();                 //数字的长度
        vector<int> visited(10, 0);
        int res = 0;
        for (int i = 1; i < k; i++) //前面为几个0 后面有效数字位数从1到k-1
            res += 9 * A(i - 1, 9); //首位为00  第1个不为0可选9个
        //前面没有0的情况
        for (int i = 0; i < k; i++) //从n的从左至右
        {
            int num = digits[i]; //这个位置上，以后的数字都要小于它  4325 选中了4  这个位置上都要小于4
            int min_digit = (i == 0 ? 1 : 0);
            for (int j = min_digit; j < num; j++) //当前位的数字
            {
                if (visited[j] == 0) //被n用了没有！！！！！！
                {
                    res += A(k - 1 - i, 10 - i - 1); //从10-i-1 个数字中挑选 k-1-i（剩余的位数）个
                }
            }
            visited[num]++;
            if (visited[num] > 1) //若n为4456  遍历了44 后面的不进行了  一定重复了
                break;
            if (i == k - 1)
                res += 1; //n自己  因为我们的假设是都比num小  但本身最右一位是相等的
        }
        return res;
    }
    int numDupDigitsAtMostN(int n)
    {
        return n - F(n);
        // int res = 0;
        // string target = to_string(n);
        // vector<int> vis(10, 0);
        // string tmp;
        // int len = target.size();
        // function<void(int)> dfs = [&](int cur) {
        //     if (cur == len && tmp > target)
        //         return;
        //     if (tmp.size() == cur)
        //     {
        //         ++res;
        //     }
        //     else
        //     {
        //         for (int i = 0; i < 10; ++i)
        //         {
        //             if (0 == tmp.size() && 0 == i)
        //                 continue;
        //             if (vis[i])
        //                 continue;
        //             vis[i] = 1;
        //             tmp.push_back('0' + i);
        //             dfs(cur);
        //             tmp.pop_back();
        //             vis[i] = 0;
        //         }
        //     }
        // };
        // for (int i = 1; i <= len; ++i)
        //     dfs(i);
        // return n - res;
    }
};
// @lc code=end
