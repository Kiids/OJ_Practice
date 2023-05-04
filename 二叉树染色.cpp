/*
С����һ�������Ϊ root �Ķ�����ģ�ͣ���ʼ���н���Ϊ��ɫ����������ɫȾ�ϸ�ģ�ͽ��Ⱦɫ��ģ�͵�ÿ�������һ�� val ��ֵ��С�۳������ۿ��ǣ�ϣ������������ÿ����ɫ�������ֵĽ��������ܳ��� k ����������Ⱦ����ɫ�Ľ���ֵ�ܺ�����Ƕ��٣�
ʾ�� 1��
���룺root = [5,2,3,4], k = 2
�����12
���ͣ���� 5��3��4 Ⱦ����ɫ��������ļ�ֵ 5+3+4=12
ʾ�� 2��
���룺root = [4,1,3,9,null,null,2], k = 2
�����16
���ͣ���� 4��3��9 Ⱦ����ɫ��������ļ�ֵ 4+3+9=16
��ʾ��
1 <= k <= 10
1 <= val <= 10000
1 <= ������� <= 10000
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
    vector<int> DFS(TreeNode* root, int k) {
        vector<int> v(k + 1, 0);
        if (!root)
            return v;
        auto l = DFS(root->left, k);
        auto r = DFS(root->right, k);
        v[0] = *max_element(l.begin(), l.end()) + *max_element(r.begin(), r.end());
        for (int i = 1; i <= k; i++)
            for (int j = 0; j < i; j++)
                v[i] = max(v[i], root->val + l[j] + r[i - j - 1]);
        return v;
    }
public:
    int maxValue(TreeNode* root, int k) {
        auto v = DFS(root, k);
        return *max_element(v.begin(), v.end());
    }
};

// f[i](0��i��k) ��ʾ�Ըýڵ�Ϊ�������ڵ��ӽڵ�Ϊ ��ɫ �ĸ���Ϊ i ������£�����������
// �ڵ��ֵ�ܺ͵����ֵ��
