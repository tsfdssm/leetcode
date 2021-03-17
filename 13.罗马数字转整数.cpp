/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        s = replace(s,"IV", "a");
        s = replace(s,"IX", "b");
        s = replace(s,"XL", "c");
        s = replace(s,"XC", "d");
        s = replace(s,"CD", "e");
        s = replace(s,"CM", "f");

        int res = 0;
        for (char& c : s)
        {
            res += romanToIntOneBit(c);
        }
        return res;
    }
private:
    int romanToIntOneBit(char c)
    {
        switch(c){
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
        
        case 'a':return 4;
        case 'b':return 9;
        case 'c':return 40;
        case 'd':return 90;
        case 'e':return 400;
        case 'f':return 900;
        default :
            return 0;
        }
    } 
    string replace(string& s,const string& a,const string& b)
    {
        int i = 0;
        for (; i < s.size() && s[i] != a[0]; i++);
        if (i == s.size())
                return s;
        int j = 0;
        for (; j < a.size() && (i + j) < s.size() && s[i + j] == a[j];j++);
        if(j!=a.size())
            return s;
        s.replace(i, j, b);
        return s;
    }
};
// @lc code=end

