/*
����һ�ö�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·���������ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��·����
ʾ��:
�������¶��������Լ�Ŀ���?sum = 22��
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
����:
[
   [5,4,11,2],
   [5,8,4,5]
]
��ʾ��
�ڵ����� <= 10000
*/

// ���� 
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;

        vector<int> path;
        dfs(root, ret, path, sum, 0);
        return ret;
    }
    // ǰ�����
    void dfs(TreeNode* root, vector<vector<int>>& ret, vector<int>& path, int sum, int cursum)
    {
        cursum += root->val;
        path.push_back(root->val);
        if (cursum == sum && root->left == nullptr && root->right == nullptr)
            ret.push_back(path);
        if (root->left)
            dfs(root->left, ret, path, sum, cursum);
        if (root->right)
            dfs(root->right, ret, path, sum, cursum);
        path.pop_back();
    }
};
