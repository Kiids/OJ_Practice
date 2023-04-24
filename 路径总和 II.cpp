/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。
示例 1：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
示例 2：
输入：root = [1,2,3], targetSum = 5
输出：[]
示例 3：
输入：root = [1,2], targetSum = 0
输出：[]
提示：
树中节点总数在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
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
    vector<vector<int>> v;
    vector<int> path;
public:
    void preorder(TreeNode* node, int path_value, int sum, vector<int>& path, vector<vector<int>>& v)
    {
        if (!node)  
            return ;
        path_value += node->val;
        path.push_back(node->val);
        if (!node->left && !node->right && path_value == sum)
            v.push_back(path);
        preorder(node->left, path_value, sum, path, v);
        preorder(node->right, path_value, sum, path, v);
        path_value -= node->val;
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        preorder(root, 0, targetSum, path, v);  // 中序遍历递归 
        return v;
    }
};

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
    vector<vector<int>> v;
    vector<int> path;
    void DFS(TreeNode *root, int sum)
    {
        path.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right)
        {
            if (!sum)
                v.push_back(path);
        }
        else
        {
            if (root->left)
                DFS(root->left, sum);
            if (root->right)
                DFS(root->right, sum);
        }        
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return v;
        DFS(root, targetSum);
        return v;
    }
};

//自上而下的递归，特殊判断根结点不能为空。
//进入新的一层，先将结点值传入路径， sum 将这一层的结点值减去，递归左右子树，传到叶子结点后，
//判断此时结点值是否为 0 ，是 0 则保存路径。弹栈时恢复现场，去掉路径最后的结点值。
//时间复杂度 : O(n) ， n 是结点个数 ，每个结点至多被遍历一次
//空间复杂度 : O(∣h∣) ， ∣h∣是二叉树的最大深度，等于压栈的最大深度 

