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
        vector<string> all(numRows);

        int k = numRows * 2 - 1;

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
                    all[2 * numRows - 2 - j].push_back(s[i]);
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

int main()
{
    freopen("C:\\Users\\Luo\\Desktop\\a.txt", "r", stdin);
    string s;
    int n;
    Solution a;
    cin >> s >> n;
    string q=a.convert(s, n);
    cout<<q;
    system("pause");
    return 0;
}
// @lc code=end
