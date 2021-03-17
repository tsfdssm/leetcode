/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>dict(256,-1);
        int start =-1,maxn=0;
        for(int i=0;i<s.size();i++)
        {
            if(dict[s[i]]>start)
                start=dict[s[i]];
            dict[s[i]]=i;
            maxn=max(maxn,i-start);
        }
        return maxn;
    }
};
// @lc code=end

