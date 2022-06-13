/*
 * @lc app=leetcode.cn id=1157 lang=cpp
 *
 * [1157] 子数组中占绝大多数的元素
 *
 * https://leetcode.cn/problems/online-majority-element-in-subarray/description/
 *
 * algorithms
 * Hard (33.95%)
 * Likes:    63
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 10.9K
 * Testcase Example:  '["MajorityChecker","query","query","query"]\n' +
  '[[[1,1,2,2,1,1]],[0,5,4],[0,3,3],[2,3,2]]'
 *
 * 设计一个数据结构，有效地找到给定子数组的 多数元素 。
 *
 * 子数组的 多数元素 是在子数组中出现 threshold 次数或次数以上的元素。
 *
 * 实现 MajorityChecker 类:
 *
 *
 * MajorityChecker(int[] arr) 会用给定的数组 arr 对 MajorityChecker 初始化。
 * int query(int left, int right, int threshold) 返回子数组中的元素  arr[left...right]
 * 至少出现 threshold 次数，如果不存在这样的元素则返回 -1。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入:
 * ["MajorityChecker", "query", "query", "query"]
 * [[[1, 1, 2, 2, 1, 1]], [0, 5, 4], [0, 3, 3], [2, 3, 2]]
 * 输出：
 * [null, 1, -1, 2]
 *
 * 解释：
 * MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
 * majorityChecker.query(0,5,4); // 返回 1
 * majorityChecker.query(0,3,3); // 返回 -1
 * majorityChecker.query(2,3,2); // 返回 2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 2 * 10^4
 * 1 <= arr[i] <= 2 * 10^4
 * 0 <= left <= right < arr.length
 * threshold <= right - left + 1
 * 2 * threshold > right - left + 1
 * 调用 query 的次数最多为 10^4 
 *
 *
 */

// @lc code=start
class MajorityChecker
{
    struct node
    {
        int x, y;
        node operator+(const node &b) const
        {
            node t;
            if (x == b.x)
            {
                t.x = x;
                t.y = y + b.y;
            }
            else if (y < b.y)
            {
                t.x = b.x;
                t.y = b.y - y;
            }
            else
            {
                t.x = x;
                t.y = y - b.y;
            }
            return t;
        }
    } t[65536];
    int n, a[20005];
    vector<int> s[20005];

    void build(int R, int l, int r)
    {
        if (l == r)
        {
            t[R].x = a[l];
            t[R].y = 1;
            return;
        }
        int mid = l + r >> 1;
        build(R << 1, l, mid);
        build(R << 1 | 1, mid + 1, r);
        t[R] = t[R << 1] + t[R << 1 | 1];
    }

    node ask(int R, int l, int r, int l1, int r1)
    {
        if (l1 == l && r == r1)
            return t[R];
        int mid = l + r >> 1;
        if (r1 <= mid)
            return ask(R << 1, l, mid, l1, r1);
        if (l1 > mid)
            return ask(R << 1 | 1, mid + 1, r, l1, r1);
        return ask(R << 1, l, mid, l1, mid) + ask(R << 1 | 1, mid + 1, r, mid + 1, r1);
    }

public:
    MajorityChecker(vector<int> &arr)
    {
        n = arr.size();
        for (int i = 0; i < n; ++i)
            s[a[i] = arr[i]].push_back(i);
        build(1, 0, n - 1);
    }

    int query(int left, int right, int threshold)
    {
        int ans = ask(1, 0, n - 1, left, right).x;
        if ((upper_bound(s[ans].begin(), s[ans].end(), right) - lower_bound(s[ans].begin(), s[ans].end(), left)) < threshold)
            ans = -1;
        return ans;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
// @lc code=end
