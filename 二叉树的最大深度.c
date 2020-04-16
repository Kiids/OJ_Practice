// 给定一个二叉树，找出其最大深度。 
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
// 说明: 叶子节点是指没有子节点的节点。
// 示例：
// 给定二叉树 [3,9,20,null,null,15,7]，
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最大深度 3 。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root){
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = 0, right = 0;
        left += maxDepth(root->left);
        right += maxDepth(root->right);
        
        return max(left, right) + 1;
    }
};


void maxdepthTraverse(struct TreeNode *root,int depth,int *maxdepth)
{
    if(root==NULL)
        return ;
    if(depth > *maxdepth)//递归过程中进行判断
        *maxdepth=depth;
    maxdepthTraverse(root->left,depth+1,maxdepth);
    maxdepthTraverse(root->right,depth+1,maxdepth);
//虽然会回溯但是不会起任何作用，这里递归是往里树下走树高度就+1，并作出判断
}
int maxDepth(struct TreeNode* root){
    int maxdep=0;
    maxdepthTraverse(root,1,&maxdep);
    return maxdep;
}

