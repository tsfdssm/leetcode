/*
 * @lc app=leetcode.cn id=587 lang=cpp
 *
 * [587] 安装栅栏
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        int L = trees.size();
        if (L < 4)
            return trees;
        vector<vector<int>> res = {};
        int max = 0;
        vector<int> start;
        for (int i = 0; i < L; i++)
        {
            if (trees[i][1] > max)
            {
                max = trees[i][1];
                start = trees[i];
            }
        }
        res.push_back(start);
        vector<int> v1 = {1, 0};
        vector<int> v2;
        vector<int> v = {0, 0};
        double cos;
        vector<int> end;
        vector<int> stop = start;
        int I;
        while (1)
        {
            double cosmax = -1.1;
            for (int i = 0; i < L; i++)
            {
                v[0] = (trees[i][0] - start[0]);
                v[1] = (trees[i][1] - start[1]);
                cos = (v[0] * v1[0] + v[1] * v1[1]) / sqrt(v[0] * v[0] + v[1] * v[1]) / sqrt(v1[0] * v1[0] + v1[1] * v1[1]);
                if (cos - cosmax > 0.00000001)
                { //我为你的计算精度误差买单。。。。
                    cosmax = cos;
                    end = trees[i];
                    I = i;
                    v2 = v;
                }
                else if (abs(cos - cosmax) < 0.00000001)
                {
                    if (pow((trees[i][0] - start[0]), 2) + pow((trees[i][1] - start[1]), 2) < pow((end[0] - start[0]), 2) + pow((end[1] - start[1]), 2))
                    {
                        end = trees[i];
                        I = i;
                        v2 = v;
                    }
                }
            }
            if (end == stop)
                break;
            res.push_back(end);
            start = end;
            v1 = v2;
            trees.erase(trees.begin() + I);
            L--;
        }
        return res;
    }
};
// @lc code=end
