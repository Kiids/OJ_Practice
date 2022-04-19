/*
给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
示例 1：
输入: root = [5,2,-3]
输出: [2,-3,4]
示例 2：
输入: root = [5,2,-5]
输出: [2]
提示:
节点数在 [1, 10^4] 范围内
-10^5 <= Node.val <= 10^5
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
    unordered_map<int, int> m;
    vector<int> v;
    int max = INT_MIN;
    int DFS(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int sum = root->val;    // sum表示以root为根的树的元素和，后序遍历，向上返回子树元素和
        sum += DFS(root->left);   
        sum += DFS(root->right);
        m[sum]++;
        if (m[sum] > max)
        {
            max = m[sum];
            v = vector<int>{ sum };
        }
        else if (m[sum] == max)
            v.push_back(sum);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        DFS(root);
        return v;
    }
};
