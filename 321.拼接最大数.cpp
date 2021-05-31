/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        int l1 = max(0, k - n);
        int r1 = min(m, k);
        vector<int> res;
        for (int i = l1; i <= r1; ++i)
        {
            vector<int> tmp1 = maxSeq(nums1, i);
            vector<int> tmp2 = maxSeq(nums2, k - i);
            vector<int> mergeRes = merge(tmp1, tmp2);
            if (!maxVec(res, 0, mergeRes, 0))
                res = mergeRes;
        }
        return res;
    }

    vector<int> maxSeq(const vector<int> &nums, const int k)
    {
        vector<int> stk;
        if (0 == k)
            return stk;
        int drop = nums.size() - k;
        if (0 == drop)
            return nums;
        for (int i = 0; drop > 0 && i < nums.size(); ++i)
        {
            while (!stk.empty() && stk.back() < nums[i] && drop > 0)
            {
                stk.pop_back();
                --drop;
            }
            if (0 == drop)
            {
                stk.insert(stk.end(), nums.begin() + i, nums.end());
                break;
            }
            stk.push_back(nums[i]);
        }
        stk.erase(stk.begin() + k, stk.end());
        return stk;
    }

    vector<int> merge(const vector<int> &nums1, const vector<int> &nums2)
    {
        int len = nums1.size() + nums2.size();
        vector<int> tmp(len);
        int i = 0, j = 0;
        for (int index = 0; index < len; ++index)
            tmp[index] = (maxVec(nums1, i, nums2, j) ? nums1[i++] : nums2[j++]);
        return tmp;
    }

    bool maxVec(const vector<int> &nums1, int i, const vector<int> &nums2, int j)
    {
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
                return false;
            else if (nums1[i] > nums2[j])
                return true;
            else
            {
                ++i;
                ++j;
            }
        }
        return (nums1.size() - i) > (nums2.size() - j);
    }
};
// @lc code=end
