/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start

#include<inttypes.h>

class Solution {
public:
    string intToRoman(int num) {
        return intToRomanOneBit(num / 1000, 'M', 0, 0) +
               intToRomanOneBit((num % 1000) / 100, 'C', 'D', 'M') +
               intToRomanOneBit((num % 100) / 10, 'X', 'L', 'C') +
               intToRomanOneBit(num % 10, 'I', 'V', 'X');
    }
private:
    string intToRomanOneBit(int num,char one,char five,char ten)
    {
        if(num<4)
            return string(num, one);
        if(num==4)
            return string("") + one + five;
        if(num<9)
            return string("") + five + string(num - 5, one);
        if(num==9)
            return string("") + one + ten;
        return 0;
    }
};
// @lc code=end

