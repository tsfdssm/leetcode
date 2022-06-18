/*
 * @lc app=leetcode.cn id=1206 lang=cpp
 *
 * [1206] 设计跳表
 *
 * https://leetcode.cn/problems/design-skiplist/description/
 *
 * algorithms
 * Hard (62.50%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    11.1K
 * Total Submissions: 17.8K
 * Testcase Example:  '["Skiplist","add","add","add","search","add","search","erase","erase","search"]\n' +
  '[[],[1],[2],[3],[0],[4],[1],[0],[1],[1]]'
 *
 * 不使用任何库函数，设计一个 跳表 。
 *
 * 跳表 是在 O(log(n))
 * 时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思想与链表相似。
 *
 * 例如，一个跳表包含 [30, 40, 50, 60, 70, 90] ，然后增加 80、45 到跳表中，以下图的方式操作：
 *
 *
 * Artyom Kalinin [CC BY-SA 3.0], via Wikimedia Commons
 *
 * 跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过 O(n)。跳表的每一个操作的平均时间复杂度是
 * O(log(n))，空间复杂度是 O(n)。
 *
 * 了解更多 : https://en.wikipedia.org/wiki/Skip_list
 *
 * 在本题中，你的设计应该要包含这些函数：
 *
 *
 * bool search(int target) : 返回target是否存在于跳表中。
 * void add(int num): 插入一个元素到跳表。
 * bool erase(int num): 在跳表中删除一个值，如果 num 不存在，直接返回false. 如果存在多个 num
 * ，删除其中任意一个即可。
 *
 *
 * 注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入
 * ["Skiplist", "add", "add", "add", "search", "add", "search", "erase",
 * "erase", "search"]
 * [[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
 * 输出
 * [null, null, null, null, false, null, true, false, true, false]
 *
 * 解释
 * Skiplist skiplist = new Skiplist();
 * skiplist.add(1);
 * skiplist.add(2);
 * skiplist.add(3);
 * skiplist.search(0);   // 返回 false
 * skiplist.add(4);
 * skiplist.search(1);   // 返回 true
 * skiplist.erase(0);    // 返回 false，0 不在跳表中
 * skiplist.erase(1);    // 返回 true
 * skiplist.search(1);   // 返回 false，1 已被擦除
 *
 *
 *
 *
 * 提示:
 *
 *
 * 0 <= num, target <= 2 * 10^4
 * 调用search, add,  erase操作次数不大于 5 * 10^4 
 *
 *
 */

// @lc code=start
class Skiplist
{
public:
    struct node
    {
        int val;
        vector<node *> nxt;

        node(int x, int len)
        {
            val = x;
            nxt.resize(len + 1, nullptr);
        }
    };
    const int MAX_LEVEL = 10;
    int level = 0;
    const double p = 0.5;
    node *phead;

    Skiplist()
    {
        phead = new node(-1, MAX_LEVEL);
    }

    int random_level()
    {
        int lvl = 0;
        double r = (double)rand() / (double)RAND_MAX;
        if (lvl < MAX_LEVEL && r > p)
        {
            ++lvl;
            r = (double)rand() / (double)RAND_MAX;
        }
        return lvl;
    };

    bool search(int target)
    {
        node *cur = phead;
        int i = level;
        for (; i >= 0; --i)
        {
            while (cur->nxt[i] != nullptr && cur->nxt[i]->val < target)
                cur = cur->nxt[i];
        }
        cur = cur->nxt[0];
        return cur != nullptr && (cur->val == target);
    }

    void add(int num)
    {
        int lvl = random_level();
        auto newNode = new node(num, lvl);
        node *cur = phead;
        level = max(level, lvl);
        int i = lvl;
        for (; i >= 0; --i)
        {
            while (cur->nxt[i] != nullptr && cur->nxt[i]->val < num)
                cur = cur->nxt[i];
            newNode->nxt[i] = cur->nxt[i];
            cur->nxt[i] = newNode;
        }
    }

    bool erase(int num)
    {
        vector<node *> update(MAX_LEVEL + 1, nullptr);
        node *cur = phead;
        int i = level;
        for (; i >= 0; --i)
        {
            while (cur->nxt[i] != nullptr && cur->nxt[i]->val < num)
                cur = cur->nxt[i];
            if ((cur->nxt[i] != nullptr) && (num == cur->nxt[i]->val))
                update[i] = cur;
        }
        cur = cur->nxt[0];
        if ((cur == nullptr) || (cur->val != num))
            return false;

        for (i = 0; i <= level; ++i)
        {
            if ((update[i] != nullptr) && (update[i]->nxt[i] == cur))
                update[i]->nxt[i] = cur->nxt[i];
            else
                break;
        }
        delete cur;
        while (level > 0 && nullptr == phead->nxt[level])
            --level;
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end
