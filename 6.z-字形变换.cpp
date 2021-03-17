/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

#include <vector>
#include <string>
#include<iostream>
using namespace std;

// @lc code=i
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if(s.size()<3||numRows<2)
            return s;
        vector<string> all(numRows);
        int k = (numRows << 1) - 2;
        //int k = numRows*2 - 2;
        int i = 0;
        int len = s.size();
        while (i < len)
        {
            for (int j = 0; j < k && i < len; i++, j++)
            {
                if (j < numRows)
                {
                    all[j].push_back(s[i]);
                }
                else
                {
                    all[k - j].push_back(s[i]);
                }
            }
        }
        s.clear();
        for (int j = 0; j < numRows; j++)
        {
            s += all[j];
        }
        return s;
    }
};

// @lc code=end
