/*
�������ö�����A��B���ж�B�ǲ���A���ӽṹ��(Լ��������������һ�������ӽṹ)
B��A���ӽṹ�� �� A���г��ֺ�B��ͬ�Ľṹ�ͽڵ�ֵ��
����:
�������� A:

     3
    / \
   4   5
  / \
 1   2
�������� B��
   4 
  /
 1
���� true����Ϊ B �� A ��һ������ӵ����ͬ�Ľṹ�ͽڵ�ֵ��
ʾ�� 1��
���룺A = [1,2,3], B = [3,1]
�����false
ʾ�� 2��
���룺A = [3,4,5,1,2], B = [4,1]
�����true
���ƣ�
0 <= �ڵ���� <= 10000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
            return false;
        return _isSubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool _isSubStructure(TreeNode* a, TreeNode* b)
    {
        if (b == nullptr)
            return true;
        if (a == nullptr || a->val != b->val)
            return false;
        return _isSubStructure(a->left, b->left) && _isSubStructure(a->right, b->right);
    }
};
