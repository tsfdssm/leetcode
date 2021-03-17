/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        vector<string> adj = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<int> digit_num;
        for (int i = 0; i < digits.size(); i++)
        {
            int c = digits[i] - '0' - 2;
            digit_num.push_back(c);
        }
        int n = digit_num.size();
        string s;
        backtrack(res, adj, digit_num, s);
        return res;
    }
    void backtrack(vector<string> &res, const vector<string> &adj,const vector<int> &digit_num, string &s)
    {
        if(s.size()==digit_num.size())
        {
            res.push_back(s);
            return;
        }
        else
        {
            int i = s.size();
            const string tmp = adj[digit_num[i]];
            for (const char c : tmp)
            {
                s.push_back(c);
                backtrack(res, adj, digit_num, s);
                s.pop_back();
            }
        }
    }
};
// @lc code=end

