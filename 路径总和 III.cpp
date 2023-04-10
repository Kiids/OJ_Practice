/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
示例 1：
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
示例 2：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
提示:
二叉树的节点个数的范围是 [0,1000]
-109 <= Node.val <= 109 
-1000 <= targetSum <= 1000 
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
    unordered_map<int, int> prefix;                     // <前缀和，出现次数>
    void DFS(TreeNode* root, int sum, int cursum, int& res)
    {
        if (!root)
            return;
        cursum += root->val;                            // 更新前缀和
        if (prefix.find(cursum - sum) != prefix.end())  // 当前路径中存在以当前节点为终点的和为sum的子路径
            res += prefix[cursum - sum];
        prefix[cursum]++;                               // 将当前节点加入路径
        DFS(root->left, sum, cursum, res);              // 左子树递归
        DFS(root->right, sum, cursum, res);             // 右子树递归
        prefix[cursum]--;                               // 回溯
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ret = 0;                                    // 满足条件的路径数量
        prefix[0] = 1;                                  // 前缀和为0的路径只有一条：哪个节点都不选
        DFS(root, targetSum, 0, ret);
        return ret;
    }
};

// 前缀和  一个节点的前缀和是该节点到根之间的路径和。
// 对于同一路径上的两个节点，上面的节点是下面节点的祖先节点，所以其前缀和之差即是这两个节点间的路径和
// （不包含祖先节点的值）。
// 哈希map：key是前缀和， value是该前缀和的节点数量，有出现复数路径的可能。
// 回溯
// 因为只有同一条路径上的节点间（节点和其某一祖先节点间）的前缀和做差才有意义。
// 所以当前节点处理完之后，需要从map中移除这个前缀和，然后再进入下一个分支路径。

