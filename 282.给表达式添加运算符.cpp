/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 */

// @lc code=start
class Solution
{
public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> res;
        string track = "";
        backtrack(num, target, 0, 0, 1, res, track);
        return res;
    }

    void backtrack(string &num, int target, int index, long val, long pre, vector<string> &res, string &track)
    {
        if (num.size() == index)
        {
            if (val == target)
                res.emplace_back(track);
            return;
        }
        int len = track.size();
        for (int i = index; i < num.size(); ++i)
        {
            string tmpS = num.substr(index, i - index + 1);
            long n = stol(tmpS);
            if (0 == index)
            {
                track += tmpS;
                backtrack(num, target, i + 1, n, n, res, track);
                track.resize(len);
            }
            else
            {
                track += "+" + tmpS;
                backtrack(num, target, i + 1, val + n, n, res, track);
                track.resize(len);

                track += "-" + tmpS;
                backtrack(num, target, i + 1, val - n, -n, res, track);
                track.resize(len);

                track += "*" + tmpS;
                backtrack(num, target, i + 1, val - pre + pre * n, pre * n, res, track);
                track.resize(len);
            }
            if (0 == n)
                return;
        }
    }
};
// @lc code=end
