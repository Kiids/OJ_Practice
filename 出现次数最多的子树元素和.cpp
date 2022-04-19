/*
����һ���������ĸ���� root ���뷵�س��ִ�����������Ԫ�غ͡�����ж��Ԫ�س��ֵĴ�����ͬ���������г��ִ�����������Ԫ�غͣ�����˳�򣩡�
һ������ ������Ԫ�غ͡� ����Ϊ�Ըý��Ϊ���Ķ����������н���Ԫ��֮�ͣ�������㱾����
ʾ�� 1��
����: root = [5,2,-3]
���: [2,-3,4]
ʾ�� 2��
����: root = [5,2,-5]
���: [2]
��ʾ:
�ڵ����� [1, 10^4] ��Χ��
-10^5 <= Node.val <= 10^5
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
    unordered_map<int, int> m;
    vector<int> v;
    int max = INT_MIN;
    int DFS(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int sum = root->val;    // sum��ʾ��rootΪ��������Ԫ�غͣ�������������Ϸ�������Ԫ�غ�
        sum += DFS(root->left);   
        sum += DFS(root->right);
        m[sum]++;
        if (m[sum] > max)
        {
            max = m[sum];
            v = vector<int>{ sum };
        }
        else if (m[sum] == max)
            v.push_back(sum);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        DFS(root);
        return v;
    }
};
