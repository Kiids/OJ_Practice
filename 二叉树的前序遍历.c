// ����һ������������������ ǰ�� ������ 
//  ʾ��:
// ����: [1,null,2,3]  
//    1
//     \
//      2
//     /
//    3 
// ���: [1,2,3]
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
int TreeNode(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return TreeNode(root->left) + TreeNode(root->right) + 1;
}

void _preorderTraversal(struct TreeNode* root, int* a, int* i)
{
    if (root == NULL)
        return;
    
    a[*i] = root->val;
    ++(*i);
    
    _preorderTraversal(root->left, a, i);
    _preorderTraversal(root->right, a, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = TreeNode(root);
    int* a = (int*)malloc(*returnSize * sizeof(int));
    
    int i = 0;
    _preorderTraversal(root, a, &i);
    
    return a;
}

