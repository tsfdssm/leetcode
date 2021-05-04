/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary
{
public:
    vector<WordDictionary *> children;
    bool isEnd;
    /** Initialize your data structure here. */
    WordDictionary() : children(26), isEnd(false)
    {
    }

    void addWord(string word)
    {
        WordDictionary *node = this;
        for (char c : word)
        {
            c -= 'a';
            if (node->children[c] == nullptr)
            {
                node->children[c] = new WordDictionary();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        return search(this, 0, word);
    }

    bool search(WordDictionary *root, int index, string &word)
    {
        if (index == word.size())
        {
            if (root->isEnd)
                return true;
            return false;
        }
        char c = word[index];
        index++;
        if (c != '.')
        {
            WordDictionary *node = root->children[c - 'a'];
            if (nullptr != node)
                return search(node, index, word);
        }
        else
        {
            auto candidates = root->children;
            for (auto candidate : candidates)
            {
                if (candidate != nullptr && search(candidate, index, word))
                    return true;
            }
        }
        return false;
    }

    WordDictionary *prefix(string word)
    {
        WordDictionary *node = this;
        for (char c : word)
        {
            c -= 'a';
            if (node->children[c] == nullptr)
            {
                return nullptr;
            }
            node = node->children[c];
        }
        return node;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
