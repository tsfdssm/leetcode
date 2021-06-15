/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        return constructTree(grid, 0, n, 0, n);
    }
    Node *constructTree(vector<vector<int>> &grid, int l, int r, int top, int bottom)
    {
        bool isLeaf = true;
        for (int i = l; i < r; ++i)
            for (int j = top; j < bottom; ++j)
            {
                if (grid[i][j] != grid[l][top])
                {
                    isLeaf = false;
                    break;
                }
            }
        if (isLeaf)
        {
            return new Node(grid[l][top], true);
        }
        int midx = (r + l) / 2;
        int midy = (bottom + top) / 2;
        Node *res = new Node();
        res->isLeaf = false;
        res->val = true;
        res->topLeft = constructTree(grid, l, midx, top, midy);
        res->topRight = constructTree(grid, l, midx, midy, bottom);
        res->bottomLeft = constructTree(grid, midx, r, top, midy);
        res->bottomRight = constructTree(grid, midx, r, midy, bottom);
        return res;
    }
};
// @lc code=end
