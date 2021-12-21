/*
�����������ĸ��ڵ� root������ÿ���ڵ㶼��һ����ͬ��ֵ��
����ڵ�ֵ�� to_delete �г��֣����ǾͰѸýڵ������ɾȥ�����õ�һ��ɭ�֣�һЩ���ཻ�������ɵļ��ϣ���
����ɭ���е�ÿ����������԰�����˳����֯�𰸡�
ʾ�� 1��
���룺root = [1,2,3,4,5,6,7], to_delete = [3,5]
�����[[1,2,null,4],[6],[7]]
ʾ�� 2��
���룺root = [1,2,4,null,3], to_delete = [3]
�����[[1,2,4]]
��ʾ��
���еĽڵ������Ϊ 1000��
ÿ���ڵ㶼��һ������ 1 �� 1000 ֮���ֵ���Ҹ�����ͬ��
to_delete.length <= 1000
to_delete ����һЩ�� 1 �� 1000��������ͬ��ֵ��
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s(begin(to_delete), end(to_delete));
        vector<TreeNode*> v;
        function<void(TreeNode*, TreeNode*, bool)> DFS = [&](TreeNode* t, TreeNode* rear, bool right)
        {
            if (!t)
                return ;
            if (s.count(t->val))
            {
                if (rear)
                    right ? rear->right = nullptr : rear->left = nullptr;
            }
            else if (!rear || s.count(rear->val))
                v.push_back(t);
            DFS(t->left, t, 0);
            DFS(t->right, t, 1);
        };  
        DFS(root, nullptr, 0);
        return v;
    }
};
