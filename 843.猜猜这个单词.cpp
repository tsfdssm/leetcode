/*
 * @lc app=leetcode.cn id=843 lang=cpp
 *
 * [843] 猜猜这个单词
 */

// @lc code=start
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution
{
    // Global variable:
    vector<vector<int>> similar;
    vector<bool> isValid;
    int len;

    // get similarity bettween words:
    void getSim(vector<string> &wordlist)
    {
        for (int i = 0; i < len; ++i)
        {
            similar[i][i] = 6;
            for (int j = i + 1; j < len; ++j)
            {
                int cnt = 0;
                for (int k = 0; k < 6; ++k)
                    cnt += (wordlist[i][k] == wordlist[j][k]);
                similar[i][j] = cnt;
                similar[j][i] = cnt;
            }
        }
    }

    // find the next search point;
    int findNext()
    {
        int next = -1, maxVal = INT_MAX;
        for (int i = 0; i < len; ++i)
        {
            if (!isValid[i])
                continue;
            vector<int> counter(6, 0);
            for (int j = 0; j < len; ++j)
            {
                if (j == i || !isValid[j])
                    continue;
                ++counter[similar[i][j]];
            }
            int currMax = *max_element(counter.begin(), counter.end());
            if (currMax < maxVal)
            {
                maxVal = currMax;
                next = i;
            }
        }
        return next;
    }

public:
    void findSecretWord(vector<string> &wordlist, Master &master)
    {
        len = wordlist.size();
        similar.resize(len, vector<int>(len, 0));
        isValid.resize(len, true);
        getSim(wordlist);

        while (true)
        {
            int next = findNext();
            int point = master.guess(wordlist[next]);
            if (point == 6)
                return;
            for (int i = 0; i < len; ++i)
            {
                if (similar[next][i] != point)
                    isValid[i] = false;
            }
        }
    }
};
// class Solution
// {
// public:
//     void findSecretWord(vector<string> &wordlist, Master &master)

//             // if (wordlist.size() <= 10)
//             // {
//             //     for (string &word : wordlist)
//             //     {
//             //         master.guess(word);
//             //     }
//             // }
//             // else
//             // {
//             //     master.guess("hbaczn");
//             //     master.guess("cymplm");
//             //     master.guess("anqomr");
//             //     master.guess("vftnkr");
//             //     master.guess("ccoyyo");
//             //     master.guess("azzzzz");
//             // }
//         }
//     }
//     int count(const string &a, const string &b)
//     {
//         int res = 0;
//         for (int i = 0; i < a.size(); ++i)
//         {
//             if (a[i] == b[i])
//                 ++res;
//         }
//         return res;
//     }
// };
// @lc code=end
