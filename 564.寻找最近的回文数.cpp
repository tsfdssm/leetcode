/*
 * @lc app=leetcode.cn id=564 lang=cpp
 *
 * [564] 寻找最近的回文数
 */

// @lc code=start
class Solution
{
public:
    string nearestPalindromic(string n)
    {
        int size = n.size();
        long num = stol(n);
        if (num <= 10)
            return to_string(num - 1);
        else if (n == "11")
            return "9";
        else if (num == pow(10, size - 1))
            return to_string(num - 1);
        else if (num == pow(10, size) - 1)
            return to_string(num + 2);
        else
        {
            string s1, s2;
            s1 = n.substr(0, (size - 1) / 2 + 1);
            int a = stol(s1);
            vector<long> left = {a - 1, a, a + 1}, nums(3), diff(3);
            vector<string> left_str = {to_string(a - 1), to_string(a), to_string(a + 1)};
            vector<string> reverse_str(3), nums_str(3);
            for (int i = 0; i < 3; i++)
            {
                reverse_str[i] = left_str[i].substr(0, n.size() - left_str[1].size());
                reverse(reverse_str[i].begin(), reverse_str[i].end());
                nums_str[i] = left_str[i] + reverse_str[i];
                nums[i] = stol(nums_str[i]);
                diff[i] = abs(nums[i] - num);
            }
            long min = num;
            int indx;
            for (int i = 0; i < 3; i++)
            {
                if (diff[i] < min && nums[i] != num)
                {
                    min = diff[i];
                    indx = i;
                }
            }
            return nums_str[indx];
        }
    }
};
// @lc code=end
