/*
 * @lc app=leetcode.cn id=726 lang=cpp
 *
 * [726] 原子的数量
 */

// @lc code=start
class Solution
{
public:
    string countOfAtoms(const string &formula)
    {
        stack<string> stk_s;
        stack<int> stk_num;

        int n = formula.size();
        vector<int> vec;
        stack<string> tmp_s;
        stack<int> tmp_num;
        for (int i = 0; i < n; ++i)
        {
            char c = formula[i];
            if ('(' == c)
            {
                stk_s.push("(");
            }
            else if (')' == c)
            {
                int j = i + 1;
                while (j < n && isDigit(formula[j]))
                    ++j;
                int multi = 1;
                if (j > i + 1)
                {
                    multi = stoi(formula.substr(i + 1, j - i - 1));
                }
                while (stk_s.top() != "(")
                {
                    tmp_s.push(stk_s.top());
                    tmp_num.push(multi * stk_num.top());
                    stk_s.pop();
                    stk_num.pop();
                }
                stk_s.pop();

                while (!tmp_s.empty())
                {
                    stk_s.push(tmp_s.top());
                    stk_num.push(tmp_num.top());
                    tmp_s.pop();
                    tmp_num.pop();
                }
                i = j - 1;
            }
            else
            {
                int j = i + 1;
                while (j < n && !isUpper(formula[j]) && (formula[j] != '(') && (formula[j] != ')'))
                    ++j;
                int k = j - 1;
                while (i < k && isDigit(formula[k]))
                    --k;
                if (k == j - 1)
                {
                    stk_num.push(1);
                }
                else
                {
                    stk_num.push(stoi(formula.substr(k + 1, j - k - 1)));
                }
                stk_s.push(formula.substr(i, k + 1 - i));
                i = j - 1;
            }
        }
        map<string, int> mp;
        while (!stk_s.empty())
        {
            auto &cur = stk_s.top();
            mp[cur] += stk_num.top();
            stk_s.pop();
            stk_num.pop();
        }
        string res;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            res += it->first;
            if (it->second > 1)
                res += to_string(it->second);
        }
        return res;
    }
    inline bool isUpper(char c)
    {
        return 'A' <= c && c <= 'Z';
    }

    inline bool isDigit(char c)
    {
        return '0' <= c && c <= '9';
    }
};
// @lc code=end
