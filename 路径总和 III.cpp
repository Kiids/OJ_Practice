/*
����һ���������ĸ��ڵ� root ����һ������ targetSum ����ö�������ڵ�ֵ֮�͵��� targetSum �� ·�� ����Ŀ��
·�� ����Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��
ʾ�� 1��
���룺root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
�����3
���ͣ��͵��� 8 ��·���� 3 ������ͼ��ʾ��
ʾ�� 2��
���룺root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
�����3
��ʾ:
�������Ľڵ�����ķ�Χ�� [0,1000]
-109 <= Node.val <= 109 
-1000 <= targetSum <= 1000 
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
    unordered_map<int, int> prefix;                     // <ǰ׺�ͣ����ִ���>
    void DFS(TreeNode* root, int sum, int cursum, int& res)
    {
        if (!root)
            return;
        cursum += root->val;                            // ����ǰ׺��
        if (prefix.find(cursum - sum) != prefix.end())  // ��ǰ·���д����Ե�ǰ�ڵ�Ϊ�յ�ĺ�Ϊsum����·��
            res += prefix[cursum - sum];
        prefix[cursum]++;                               // ����ǰ�ڵ����·��
        DFS(root->left, sum, cursum, res);              // �������ݹ�
        DFS(root->right, sum, cursum, res);             // �������ݹ�
        prefix[cursum]--;                               // ����
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ret = 0;
        prefix[0] = 1;
        DFS(root, targetSum, 0, ret);
        return ret;
    }
};
