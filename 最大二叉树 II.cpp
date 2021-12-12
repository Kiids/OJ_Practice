/*
��������壺һ����������ÿ���ڵ��ֵ�������������е��κ�����ֵ��
����������ĸ��ڵ� root��
����֮ǰ���������������������Ǵ��б� A��root = Construct(A)���ݹ��ʹ������ Construct(A) ���̹���ģ�
��� A Ϊ�գ����� null
������ A[i] ��Ϊ A �����Ԫ�ء�����һ��ֵΪ A[i] �ĸ��ڵ� root
root ����������������Ϊ Construct([A[0], A[1], ..., A[i-1]])
root ����������������Ϊ Construct([A[i+1], A[i+2], ..., A[A.length - 1]])
���� root
��ע�⣬����û��ֱ�Ӹ��� A��ֻ��һ�����ڵ� root = Construct(A).
���� B �� A �ĸ���������ĩβ����ֵ val����Ŀ���ݱ�֤ B �е�ֵ�ǲ�ͬ�ġ�
���� Construct(B)��
ʾ�� 1��
���룺root = [4,1,3,null,null,2], val = 5
�����[5,4,null,1,3,null,null,2]
���ͣ�A = [1,4,2,3], B = [1,4,2,3,5]
ʾ�� 2��
���룺root = [5,2,4,null,1], val = 3
�����[5,2,4,null,1,null,3]
���ͣ�A = [2,1,5,4], B = [2,1,5,4,3]
ʾ�� 3��
���룺root = [5,2,3,null,1], val = 4
�����[5,2,4,null,1,3]
���ͣ�A = [2,1,5,3], B = [2,1,5,3,4]
��ʾ��
1 <= B.length <= 100
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == nullptr || val > root->val)
        {
            TreeNode* cur = new TreeNode(val);
            cur->left = root;
            return cur;
        }
        else if (val < root->val)
        {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
        return nullptr;
    }
};
