/*
����һ������ n ���������ɲ����������� n ���ڵ�����ҽڵ�ֵ�� 1 �� n ������ͬ�Ĳ�ͬ ���������� �����԰� ����˳�� ���ش𰸡�
ʾ�� 1��
���룺n = 3
�����[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
ʾ�� 2��
���룺n = 1
�����[[1]]
��ʾ��
1 <= n <= 8
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return fun(1, n);
    }

    vector<TreeNode*> fun(int st, int n)
    {
        vector<TreeNode*> v;
        if (st > n)
            return {NULL};
        for (int i = st; i <= n; i++)
        {
            for (auto& l : fun(st, i - 1))
            {
                for (auto& r : fun(i + 1, n))
                {
                    TreeNode* root = new TreeNode(i, l, r);
                    v.push_back(root);
                }
            }            
        }
        return v;
    }
};

// �ݹ�  ���ν�ÿ�������Ϊ���ڵ� 


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
    vector<vector<vector<TreeNode*>>> v;  // ���仯 
    vector<TreeNode*> fun(int l, int r)
    {
        vector<TreeNode*> ret;
        // �߽�����
        if (l > r)
            return {NULL};
        if (!v[l][r].empty())
            return v[l][r];
        // �ݹ�
        for (int i = l; i <= r; i++)
        {
            for (auto& l : fun(l, i - 1))
            {
                for (auto& r : fun(i + 1, r))
                {
                    TreeNode* root = new TreeNode(i, l, r);
                    ret.push_back(root);
                }
            }            
        }
        return v[l][r] = ret;  // ���仯���
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        v.resize(n + 1, vector<vector<TreeNode*>>(n + 1));  // ���仯��� 
        if (n == 0)
            return {};
        return fun(1, n);
    }
};

// ��i��j֮�������һ���ڵ���Ϊ���ڵ㣬����ȡkΪ���ڵ㣬��ô��������i��k-1��ɵĶ�����������
// ������Ϊk+1��j֮�������ɵĶ�����������
// Ϊ�˱����ظ�����������һ����ϣ���������Ѿ�������i��j

