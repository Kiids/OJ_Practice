/*
����һ�Ÿ����Ϊ root �Ķ����������е�ÿһ����㶼��һ�� [0, 25] ��Χ�ڵ�ֵ���ֱ������ĸ 'a' �� 'z'��
���� ���ֵ�����С ���ַ��������ַ������������һ��Ҷ��㿪ʼ��������������
ע���ַ������κν϶̵�ǰ׺�� �ֵ����� ���� ��С �ģ�
���磬���ֵ����� "ab" �� "aba" ҪС��Ҷ�����ָû���ӽ��Ľ�㡣 
�ڵ��Ҷ�ڵ���û���ӽڵ�Ľڵ㡣
ʾ�� 1��
���룺root = [0,1,2,3,4,3,4]
�����"dba"
ʾ�� 2��
���룺root = [25,1,3,1,3,0,2]
�����"adz"
ʾ�� 3��
���룺root = [2,2,1,null,1,0,null,0]
�����"abc"
��ʾ��
�������Ľ������ [1, 8500] ��Χ��
0 <= Node.val <= 25
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
    string s = "";
    void DFS(TreeNode* root, string& curr)
    {
        if (root == nullptr)
            return;
        curr += 'a' + root->val;  // Ĭ�ϼӵ�ǰ����ַ�
        if (root->left == nullptr && root->right == nullptr)  // Ҷ�ӣ��Ѿ��ҵ�һ����������½��
        {
            string str = curr;
            reverse(str.begin(), str.end());
            if (s.empty() || str < s)
                s = str;
        }
        DFS(root->left, curr);
        DFS(root->right, curr);
        curr.pop_back();  // ����
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string curr = "";
        DFS(root, curr);
        return s;
    }
};
