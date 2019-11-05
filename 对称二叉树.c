// ����һ����������������Ƿ��Ǿ���ԳƵġ�
// ���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// ����������� [1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// ˵��:
// �����������õݹ�͵������ַ������������⣬��ܼӷ֡�

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

