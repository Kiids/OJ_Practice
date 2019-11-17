// 给定一个二叉树，返回它的中序 遍历。 
// 示例:
// 输入: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
// 输出: [1,3,2]
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int TreeNode(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return TreeNode(root->left) + TreeNode(root->right) + 1;
}

void _inorderTraversal(struct TreeNode* root, int* a, int* i)
{
    if (root == NULL)
        return;
    
    _inorderTraversal(root->left, a, i);
    a[*i] = root->val;
    ++(*i);
    _inorderTraversal(root->right, a, i);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = TreeNode(root);
    int* a = (int*)malloc(*returnSize * sizeof(int));
    
    int i = 0;
    _inorderTraversal(root, a, &i);
    
    return a;
}

