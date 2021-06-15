/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 */

// @lc code=start
class Solution
{
public:
    string originalDigits(string s)
    {
        vector<int> count(26, 0); // hashmap letter
        for (auto ch : s)
        {
            count[(ch - 'a')]++;
        }
        vector<int> out(10, 0); // hashmap digit
        out[0] = count[('z' - 'a')];
        out[2] = count[('w' - 'a')];
        out[4] = count[('u' - 'a')];
        out[6] = count[('x' - 'a')];
        out[8] = count[('g' - 'a')];

        out[3] = count[('h' - 'a')] - out[8];
        out[5] = count[('f' - 'a')] - out[4];
        out[7] = count[('s' - 'a')] - out[6];
        out[9] = count[('i' - 'a')] - out[5] - out[6] - out[8];
        out[1] = count[('n' - 'a')] - out[7] - 2 * out[9];

        // building output string
        string output = "";
        for (int i = 0; i < 10; i++)
        {
            output += string(out[i], '0' + i);
        }
        return output;
    }
};
// @lc code=end
