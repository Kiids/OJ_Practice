/*
����һ���������ĸ��ڵ� root������ڵ�λ�ڶ������ĵ� 1 �㣬�����ڵ���ӽڵ�λ�ڵ� 2 �㣬�������ơ�
�����ҳ�����Ԫ��֮�� ��� ���Ǽ��㣨����ֻ��һ�㣩�Ĳ�ţ����������� ��С ���Ǹ���
ʾ�� 1��
���룺root = [1,7,0,7,-8,null,null]
�����2
���ͣ�
�� 1 ���Ԫ��֮��Ϊ 1��
�� 2 ���Ԫ��֮��Ϊ 7 + 0 = 7��
�� 3 ���Ԫ��֮��Ϊ 7 + -8 = -1��
�������Ƿ��ص� 2 ��Ĳ�ţ����Ĳ���Ԫ��֮�����
ʾ�� 2��
���룺root = [989,null,10250,98693,-89388,null,null,null,-32127]
�����2
��ʾ��
���еĽڵ������� 1 �� 10^4 ֮��
-10^5 <= node.val <= 10^5
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
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> q{{root}};
        int maxSum = INT_MIN, ret = 0, level = 0;
        while (!q.empty())
        {
            int levelSum = 0, n = q.size();
            while (n--)
            {
                auto cur = q.front();
                q.pop();
                levelSum += cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            level++;
            if (levelSum > maxSum)
            {
                maxSum = levelSum;
                ret = level;
            }
        }   
        return ret;
    }
};
