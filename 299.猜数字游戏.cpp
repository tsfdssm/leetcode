/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int a = 0;
        int b = 0;
        map<char, int> sec;

        int n = secret.size();
        for (int i = 0; i < n; ++i)
        {
            if (secret[i] == guess[i])
            {
                ++a;
            }
            else
            {
                sec[secret[i]]++;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (secret[i] == guess[i])
                continue;
            if (sec.find(guess[i]) != sec.end() && sec[guess[i]] > 0)
            {
                ++b;
                --sec[guess[i]];
            }
        }

        return to_string(a) + "A" + to_string(b) + "B";
    }
};
// @lc code=end
