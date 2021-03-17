/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        int min = 200;
        for (int i = 0; i < strs.size();i++)
            min = min < strs[i].size() ? min : strs[i].size();
        int i = 0;
        bool isSame = true;
        for (; i < min&&isSame;i++)
        {
            char c;
            for (int j = 0; j < strs.size(); j++)
                if(j==0)
                    c = strs[0][i];
                else if(c!=strs[j][i])
                    return strs[0].substr(0, i);
        }
        return strs[0].substr(0, i);
    }
};
// @lc code=end

