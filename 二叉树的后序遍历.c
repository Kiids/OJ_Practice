// ����һ������������������ ���� ������ 
// ʾ��:
// ����: [1,null,2,3]  
//    1
//     \
//      2
//     /
//    3 
// ���: [3,2,1]
// ����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����

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
int TreeSum(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return TreeSum(root->left) + TreeSum(root->right) + 1;
}

void _postorderTraversal(struct TreeNode* root, int* a, int* i)
{
    if (root == NULL)
        return;
    _postorderTraversal(root->left, a, i);
    _postorderTraversal(root->right, a, i);
    a[*i] = root->val;
    ++(*i);
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = TreeSum(root);
    int* a = malloc(*returnSize * sizeof(int));
    int i = 0;
    _postorderTraversal(root, a, &i);
    return a;
}

