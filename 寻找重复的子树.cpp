/*
����һ�ö����� root�����������ظ���������
����ͬһ����ظ���������ֻ��Ҫ������������һ�õĸ���㼴�ɡ�
���������������ͬ�Ľṹ����ͬ�Ľ��ֵ�����������ظ��ġ�
ʾ�� 1��
���룺root = [1,2,3,4,null,2,4,null,null,4]
�����[[2,4],[4]]
ʾ�� 2��
���룺root = [2,1,1]
�����[[1]]
ʾ�� 3��
���룺root = [2,2,2,3,null,3,null]
�����[[2,3],[3]]
��ʾ��
���еĽ������[1,10^4]��Χ�ڡ�
-200 <= Node.val <= 200
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
    vector<TreeNode*> v;
    unordered_map<string, int> m;
    string DFS(TreeNode* root)
    {
        if (!root)
            return "#";
        string s = to_string(root->val) + "-" + DFS(root->left) + "-" + DFS(root->right);
        m[s]++;
        if (m.count(s) == 1 && m[s] == 2)
            v.push_back(root);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::cout << DFS(root) << std::endl;
        return v;
    }
};

//���������л��洢�ڹ�ϣ��ͳ��ÿ��������Ӧ���г��ֵĴ���

