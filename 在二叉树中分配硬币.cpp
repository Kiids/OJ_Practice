/*
给定一个有 N 个结点的二叉树的根结点 root，树中的每个结点上都对应有 node.val 枚硬币，并且总共有 N 枚硬币。
在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。(移动可以是从父结点到子结点，或者从子结点移动到父结点。)。
返回使每个结点上只有一枚硬币所需的移动次数。
示例 1：
输入：[3,0,0]
输出：2
解释：从树的根结点开始，我们将一枚硬币移到它的左子结点上，一枚硬币移到它的右子结点上。
示例 2：
输入：[0,3,0]
输出：3
解释：从根结点的左子结点开始，我们将两枚硬币移到根结点上 [移动两次]。然后，我们把一枚硬币从根结点移到右子结点上。
示例 3：
输入：[1,0,2]
输出：2
示例 4：
输入：[1,0,0,null,3]
输出：4
提示：
1<= N <= 100
0 <= node.val <= N
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
    int distributeCoins(TreeNode* root) {
        int ret = 0;
        DFS(root, ret);
        return ret;
    }

    int DFS(TreeNode* root, int& ret)
    {
        if (root == nullptr)
            return 0;
        int left = DFS(root->left, ret);
        int right = DFS(root->right, ret);
        ret += abs(left) + abs(right);  // 移动次数就是过载量的绝对值之和
        return root->val + left + right - 1;
    }
};

//递归
//计算需要移动的量就是 abs(val-1)
//定义DFS(TreeNode*) 表示这个节点的过载量，即总数-节点数,可能是正数或者负数
//当前的过载量: 当前节点数量 + dfs(left) + dfs(right) - 1

