// 给定一个二叉树，检查它是否是镜像对称的。
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// 说明:
// 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* p1, struct TreeNode* p2)
{
    if (p1 == NULL && p2 == NULL)
        return true;
    if (p1 == NULL || p2 == NULL)
        return false;
    return (p1->val == p2->val) && isMirror(p1->left, p2->right) && isMirror(p1->right, p2->left);
}

bool isSymmetric(struct TreeNode* root){
    return isMirror(root, root);
}

