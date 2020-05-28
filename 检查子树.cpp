/*
����������������÷ǳ���Ķ�������T1���м�����ڵ㣻T2���м�����ڵ㡣���һ���㷨���ж� T2 �Ƿ�Ϊ T1 ��������
��� T1 ����ôһ���ڵ� n���������� T2 һģһ������ T2 Ϊ T1 ��������Ҳ����˵���ӽڵ� n ���������ϣ��õ������� T2 ��ȫ��ͬ��
ʾ��1:
 ���룺t1 = [1, 2, 3], t2 = [2]
 �����true
ʾ��2:
 ���룺t1 = [1, null, 2, 4], t2 = [3, 2]
 �����false
��ʾ��
���Ľڵ���Ŀ��ΧΪ[0, 20000]��
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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        string s1 = "", s2 = "";
        inorder(t1, s1);
        inorder(t2, s2);
        if (s1.find(s2) != -1)
            return true;
        return false;
    }
    void inorder(TreeNode* t, string& s)
    {
        if (t == NULL)
            return;
        inorder(t->left, s);
        s += to_string(t->val);
        inorder(t->right, s);
    }
};
