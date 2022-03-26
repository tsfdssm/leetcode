/*
 * @lc app=leetcode.cn id=1036 lang=cpp
 *
 * [1036] 逃离大迷宫
 */

// @lc code=start

class Solution
{
private:
    int dires[5] = {1, 0, -1, 0, 1};
    unordered_set<long> block;
    long maxSize = 1000000;
    int maxSteps = 19900;

    bool isOk(vector<int> &source, vector<int> &target)
    {
        unordered_set<long> visited;
        visited.insert((long)source[0] * maxSize + (long)source[1]);
        queue<pair<int, int>> q;
        q.emplace(source[0], source[1]);

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                long nx = x + dires[i];
                long ny = y + dires[i + 1];
                if (nx >= 0 && nx < maxSize && ny >= 0 && ny < maxSize)
                {
                    long curr = nx * maxSize + ny;
                    // 忽略已经遍历或者block的位置
                    if (visited.find(curr) == visited.end() && block.find(curr) == block.end())
                    {
                        // 找到终点，则返回true
                        if (nx == target[0] && ny == target[1])
                        {
                            return true;
                        }

                        q.emplace(nx, ny);
                        visited.insert(curr);
                    }
                }
            }

            // 超过最大可能阻塞的步数，则必然能达到
            if (visited.size() > maxSteps)
            {
                return true;
            }
        }

        return false;
    }

public:
    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
    {
        for (vector<int> &a : blocked)
        {
            block.insert((long)a[0] * maxSize + (long)a[1]);
        }

        return isOk(source, target) && isOk(target, source);
    }
};
// @lc code=end
