/*
 * @lc app=leetcode.cn id=558 lang=cpp
 *
 * [558] 四叉树交集
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
    Node *intersect(Node *quadTree1, Node *quadTree2)
    {
        if (quadTree1->isLeaf)
        {
            if (quadTree1->val)
                return quadTree1;
            return quadTree2;
        }
        if (quadTree2->isLeaf)
        {
            if (quadTree2->val)
                return quadTree2;
            return quadTree1;
        }
        Node *c = new Node();
        c->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        c->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        c->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        c->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        bool merge = false;
        if (c->topLeft->isLeaf && c->topRight->isLeaf && c->bottomLeft->isLeaf && c->bottomRight->isLeaf)
        {
            bool tag = c->topLeft->val;
            if (c->topRight->val == tag && c->bottomLeft->val == tag && c->bottomRight->val == tag)
            {
                merge = true;
            }
        }

        if (merge)
        {
            c->isLeaf = true;
            c->val = c->topLeft->val;
            c->topLeft = c->topRight = c->bottomLeft = c->bottomRight = nullptr;
        }
        return c;
    }
};
// @lc code=end
