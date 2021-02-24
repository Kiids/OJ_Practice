/*
返回与给定前序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。
(回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 > node.val。此外，前序遍历首先显示节点 node 的值，然后遍历 node.left，接着遍历 node.right。）
题目保证，对于给定的测试用例，总能找到满足要求的二叉搜索树。
示例：
输入：[8,5,1,7,10,12]
输出：[8,5,10,1,7,null,12]
提示：
1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
preorder 中的值互不相同
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
    int i;
    vector<int> v;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        v = preorder;
        return DFS(INT_MIN, INT_MAX);
    }

    TreeNode* DFS(int l, int r)
    {
        if (i == v.size() || v[i] < l || v[i] > r)
            return nullptr;
        TreeNode* ret = new TreeNode(v[i++]);
        ret->left = DFS(l, ret->val);
        ret->right = DFS(ret->val, r);
        return ret;
    }
};
