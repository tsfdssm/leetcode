/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (0 == denominator)
            return "";
        if (0 == numerator)
            return "0";
        string res;

        if (numerator > 0 ^ denominator > 0)
            res.push_back('-');
        long long num = llabs(numerator);
        long long den = llabs(denominator);
        long long beforePoint = num / den, afterPoint = num % den;
        if (beforePoint == 0)
        {
            res.push_back('0');
        }
        else
        {
            while (beforePoint > 0)
            {
                res.push_back('0' + beforePoint % 10);
                beforePoint /= 10;
            }
            if (res[0] == '-')
                reverse(res.begin() + 1, res.end());
            else
                reverse(res.begin(), res.end());
        }
        if (afterPoint == 0)
        {
            return res;
        }
        else
        {
            res.push_back('.');
            unordered_map<int, int> hash;
            int index = 0;

            while (afterPoint != 0)
            {
                if (0 == hash.count(afterPoint))
                    hash[afterPoint] = index;
                else
                {
                    res.insert(res.begin() + res.size() - index + hash[afterPoint], '(');
                    res.push_back(')');
                    break;
                }

                afterPoint *= 10;
                int num1 = afterPoint / den;
                int num2 = afterPoint % den;
                res.push_back('0' + num1);
                afterPoint = num2;
                index++;
            }
        }
        return res;
    }
};
// @lc code=end
