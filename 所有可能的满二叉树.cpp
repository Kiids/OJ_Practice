/*
满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。
返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。
答案中每个树的每个结点都必须有 node.val=0。
你可以按任何顺序返回树的最终列表。
示例：
输入：7
输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
解释：
提示：
1 <= N <= 20
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> dp;
        // 边界条件1:如果输入的是偶数，return一个空列表
        if (N & 1 == 0)
            return dp;
        // 边界条件2:如果输入为1，那么结果就只有一个值为0的结点
        if (N == 1)
        {
            dp.push_back(new TreeNode(0));
            return dp;
        }

        // 一共有N个结点，root占了1个结点，左子树可能有1，3，5，..，N-2个结点
        // 右子树可能有N-2，..，5，3，1个结点
        // 用一个循环，找到所有可能的左右子树的可能的数量的情况，把root放进列表里
        for (int i = 1; i <= N - 2; i += 2)
        {
            // allPossibleFBT(i)返回了一个列表，它存放着当结点数为i时，所有满足条件的树的root的集合
            // allPossibleFBT(i)存放着所有满足条件的左子树的集合
            // allPossibleFBT(N-1-i)存放着所有满足条件的右子树的集合
            // 由vector<TreeNode*> allPossibleFBT(int N)这个函数的定义所确定的
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N - 1 - i);

            // 左右子树的排列组合，当左子树为m时，右子树可能有right.size()个可能
            // 一共有right.size() * left.size()种可能
            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    // 对于左子树有i个结点，右子树有N-1-i个结点时，把所有可能的树push进入队列
                    dp.push_back(root);
                }
            }
        }
        return dp;
    }
};
