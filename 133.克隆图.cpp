/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <unordered_map>
#include <unordered_set>
//#include <pair>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const pair<T1, T2> &p) const
    {
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};
class Solution
{
public:
    // unordered_set<pair<int, int>, pair_hash> mp;
    // Node *dfs(Node *node)
    // {
    //     if (nullptr == node)
    //         return nullptr;
    //     Node *newNode = new Node(node->val);
    //     for (int i = 0; i < node->neighbors.size(); ++i)
    //     {
    //         Node *tmp = node->neighbors[i];
    //         if (mp.count({node->val, tmp->val}) == 0)
    //         {
    //             mp.insert({node->val, tmp->val});
    //             mp.insert({tmp->val, node->val});
    //             newNode->neighbors.push_back(dfs(tmp));
    //             //newNode->neighbors.push_back(newTmp);
    //         }
    //     }
    //     return newNode;
    // }
    unordered_map<Node *, Node *> mp;
    Node *cloneGraph(Node *node)
    {
        if (nullptr == node)
            return nullptr;
        if (mp.find(node) != mp.end())
            return mp.find(node)->second;
        Node *newNode = new Node(node->val);
        mp.insert({node, newNode});
        for (const auto &tmp : node->neighbors)
        {
            newNode->neighbors.push_back(cloneGraph(tmp));
        }

        return newNode;
        //return dfs(node);
    }
};
// @lc code=end
