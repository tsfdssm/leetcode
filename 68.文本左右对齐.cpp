/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        int tmp = maxWidth;
        vector<string> str;
        string s;
        for (int i = 0; i < words.size(); i++)
        {
            if (tmp < (int)words[i].size())
            {
                if (1 == str.size())
                    s = str[0] + string(maxWidth - str[0].size(), ' ');
                else
                {
                    int n = str.size() - 1;
                    int space = tmp + str.size();
                    int num_space = space / n;
                    int extra = space % n;
                    for (int j = 0; j < str.size(); j++)
                    {
                        s += str[j];
                        if (j < extra)
                            s += string(num_space + 1, ' ');
                        else if (j < str.size() - 1)
                            s += string(num_space, ' ');
                        else
                        {
                        }
                    }
                }
                str.clear();
                res.emplace_back(s);
                s.clear();
                str.push_back(words[i]);
                tmp = maxWidth - words[i].size() - 1;
            }
            else
            {
                str.push_back(words[i]);
                tmp -= (words[i].size() + 1);
            }
        }
        if (!str.empty())
        {
            for (int i = 0; i < str.size() - 1; i++)
                s += str[i] + ' ';
            s += str.back();
            if (tmp >= 0)
                s += string(tmp + 1, ' ');

            res.emplace_back(s);
        }
        return res;
    }
};
// @lc code=end
