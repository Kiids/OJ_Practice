/*
给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。
请你找出层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。
示例 1：
输入：root = [1,7,0,7,-8,null,null]
输出：2
解释：
第 1 层各元素之和为 1，
第 2 层各元素之和为 7 + 0 = 7，
第 3 层各元素之和为 7 + -8 = -1，
所以我们返回第 2 层的层号，它的层内元素之和最大。
示例 2：
输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
输出：2
提示：
树中的节点数介于 1 和 10^4 之间
-10^5 <= node.val <= 10^5
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> q{{root}};
        int maxSum = INT_MIN, ret = 0, level = 0;
        while (!q.empty())
        {
            int levelSum = 0, n = q.size();
            while (n--)
            {
                auto cur = q.front();
                q.pop();
                levelSum += cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            level++;
            if (levelSum > maxSum)
            {
                maxSum = levelSum;
                ret = level;
            }
        }   
        return ret;
    }
};
