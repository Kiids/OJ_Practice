/*
����һ������ֵͬ�Ķ�����������BST�����ҳ� BST �е���������������Ƶ����ߵ�Ԫ�أ���
�ٶ� BST �����¶��壺
�������������������ֵС�ڵ��ڵ�ǰ����ֵ
�������������������ֵ���ڵ��ڵ�ǰ����ֵ
�����������������Ƕ���������
���磺
���� BST [1,null,2,2],
   1
    \
     2
    /
   2
����[2].
��ʾ�������������1�������迼�����˳��
���ף�����Բ�ʹ�ö���Ŀռ��𣿣������ɵݹ��������ʽ����ջ�Ŀ��������������ڣ�
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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> dict;
        vector<int> ret;
        int count = DFS(root, dict);
        for (auto &[key, value] : dict)
            if (value == count)
                ret.push_back(key);
        return ret;
    }

    int DFS(TreeNode *root, unordered_map<int, int> &dict)
    {
        if (!root)
            return 0;
        dict[root->val]++;
        return max(dict[root->val], max(DFS(root->left, dict), DFS(root->right, dict)));
    }
};
