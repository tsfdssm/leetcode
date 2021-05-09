/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, string> oneToNineteen;
    unordered_map<int, string> twtyToNity;
    //处理百十个位
    void help(int hundred, string &ans)
    {
        if (hundred != 0)
        { //处理百
            int num1 = hundred / 100, num2 = hundred % 100 / 10, num3 = hundred % 10;
            if (num1 != 0)
                ans += oneToNineteen[num1] + " Hundred ";
            if (num2 == 0)
            {
                if (num3 != 0)
                    ans += oneToNineteen[num3] + " ";
            }
            else if (2 <= num2 && num2 <= 9)
            {
                ans += twtyToNity[num2] + " ";
                if (num3 != 0)
                    ans += oneToNineteen[num3] + " ";
            }
            else
            {
                ans += oneToNineteen[num2 * 10 + num3] + " ";
            }
        }
    }
    //记录1-19、20-90的英文
    void numOfEnlish()
    {
        oneToNineteen[1] = "One", oneToNineteen[2] = "Two", oneToNineteen[3] = "Three", oneToNineteen[4] = "Four",
        oneToNineteen[5] = "Five", oneToNineteen[6] = "Six", oneToNineteen[7] = "Seven", oneToNineteen[8] = "Eight",
        oneToNineteen[9] = "Nine", oneToNineteen[10] = "Ten", oneToNineteen[11] = "Eleven",
        oneToNineteen[12] = "Twelve", oneToNineteen[13] = "Thirteen", oneToNineteen[14] = "Fourteen",
        oneToNineteen[15] = "Fifteen", oneToNineteen[16] = "Sixteen", oneToNineteen[17] = "Seventeen",
        oneToNineteen[18] = "Eighteen", oneToNineteen[19] = "Nineteen";
        twtyToNity[2] = "Twenty", twtyToNity[3] = "Thirty", twtyToNity[4] = "Forty", twtyToNity[5] = "Fifty",
        twtyToNity[6] = "Sixty", twtyToNity[7] = "Seventy", twtyToNity[8] = "Eighty", twtyToNity[9] = "Ninety";
    }
    //转换为英文
    void transform(int num, string &ans)
    {
        int base = 1000;
        int hundred = num % base;                        //记录为百的三位数
        int thousand = num / (base) % base;              //记录为千的三位数
        int million = num / (base * base) % base;        //记录为百万的三位数
        int billion = num / (base * base * base) % base; //记录为十亿的三位数
        if (billion != 0)
            help(billion, ans), ans += "Billion "; //处理十亿
        if (million != 0)
            help(million, ans), ans += "Million "; //处理百万
        if (thousand != 0)
            help(thousand, ans), ans += "Thousand "; //处理千
        help(hundred, ans);                          //处理百
    }
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero"; //遇到为0直接返回zero
        numOfEnlish();
        string ans;
        transform(num, ans);
        ans.erase(ans.size() - 1); //删除最后一位多出的空格
        return ans;
    }
};

// @lc code=end
