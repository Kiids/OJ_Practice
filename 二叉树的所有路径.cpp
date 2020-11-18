/*
����һ�����������������дӸ��ڵ㵽Ҷ�ӽڵ��·����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
ʾ��:
����:
   1
 /   \
2     3
 \
  5
���: ["1->2->5", "1->3"]
����: ���и��ڵ㵽Ҷ�ӽڵ��·��Ϊ: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string s;
        if (root == NULL)
            return ret;
        DFS(root, s, ret);
        return ret;
    }

    void DFS(TreeNode* cur, string path, vector<string>& v)
    {
        path += to_string(cur->val);
        if (cur->left == NULL && cur->right == NULL)
        {
            v.push_back(path);
            return;
        }
        if (cur->left)
            DFS(cur->left, path + "->", v);
        if (cur->right)
            DFS(cur->right, path + "->", v);
    }
};
