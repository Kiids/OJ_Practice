/*
�뿼��һ�ö����������е�Ҷ�ӣ���ЩҶ�ӵ�ֵ�������ҵ�˳�������γ�һ�� Ҷֵ���� ��
�ٸ����ӣ�����ͼ��ʾ������һ��Ҷֵ����Ϊ (6, 7, 4, 9, 8) ������
��������ö�������Ҷֵ��������ͬ����ô���Ǿ���Ϊ������ Ҷ���� �ġ�
�������������ͷ���ֱ�Ϊ root1 �� root2 ������Ҷ���Ƶģ��򷵻� true�����򷵻� false ��
ʾ�� 1��
���룺root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
�����true
ʾ�� 2��
���룺root1 = [1], root2 = [1]
�����true
ʾ�� 3��
���룺root1 = [1], root2 = [2]
�����false
ʾ�� 4��
���룺root1 = [1,2], root2 = [2,2]
�����true
ʾ�� 5��
���룺root1 = [1,2,3], root2 = [1,3,2]
�����false
��ʾ��
���������������ܻ��� 1 �� 200 ����㡣
�������������ϵ�ֵ���� 0 �� 200 ֮�䡣
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        preOrder(root1, v1);
        preOrder(root2, v2);
        return v1 == v2;
    }

    void preOrder(TreeNode* n, vector<int>& v)
    {
        if (n == nullptr)
            return;

        if (n->left == nullptr && n->right == nullptr)
            v.push_back(n->val);
        preOrder(n->left, v);
        preOrder(n->right, v);
    }
};
