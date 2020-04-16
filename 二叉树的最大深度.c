// ����һ�����������ҳ��������ȡ� 
// �����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
// ˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
// ʾ����
// ���������� [3,9,20,null,null,15,7]��
//     3
//    / \
//   9  20
//     /  \
//    15   7
// �������������� 3 ��

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
    if(depth > *maxdepth)//�ݹ�����н����ж�
        *maxdepth=depth;
    maxdepthTraverse(root->left,depth+1,maxdepth);
    maxdepthTraverse(root->right,depth+1,maxdepth);
//��Ȼ����ݵ��ǲ������κ����ã�����ݹ����������������߶Ⱦ�+1���������ж�
}
int maxDepth(struct TreeNode* root){
    int maxdep=0;
    maxdepthTraverse(root,1,&maxdep);
    return maxdep;
}

