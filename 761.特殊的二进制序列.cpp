/*
 * @lc app=leetcode.cn id=761 lang=cpp
 *
 * [761] 特殊的二进制序列
 */

// @lc code=start
class Solution
{
public:
    string makeLargestSpecial(string S)
    {
        int cnt = 0;
        vector<string> vc;
        int pos = 0;

        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '0')
            {
                cnt += -1;
            }
            else
            {
                cnt += 1;
            }
            //printf("%d %c\r\n", cnt);
            if (cnt == 0)
            {
                vc.push_back('1' + makeLargestSpecial(S.substr(pos + 1, i - pos - 1)) + '0');
                pos = i + 1;
            }
        }

        string ret;

        sort(vc.begin(), vc.end(), greater<string>());
        for (int i = 0; i < vc.size(); i++)
        {

            ret += vc[i];
        }
        return ret;
    }
};
// class Solution
// {
// public:
//     string makeLargestSpecial(string s)
//     {
//         //mine:100%
//         int n = s.size();
//         if (0 == n)
//             return "";
//         if (2 == n)
//             return "10";
//         int cnt = 0;
//         int pos = 0;
//         vector<string> vec;
//         for (int i = 0; i < n; ++i)
//         {
//             if (s[i] == '1')
//                 ++cnt;
//             else
//                 --cnt;
//             if (0 == cnt)
//             {
//                 vec.emplace_back("1" + makeLargestSpecial(s.substr(pos + 1, i - pos - 1)) + "0");
//                 pos = i + 1;
//             }
//         }
//         sort(vec.begin(), vec.end(), greater<string>());
//         string res;
//         for (string &str : vec)
//             res += str;
//         return res;
//     }
// };
// @lc code=end
