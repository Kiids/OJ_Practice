/*
小扣有一个根结点为 root 的二叉树模型，初始所有结点均为白色，可以用蓝色染料给模型结点染色，模型的每个结点有一个 val 价值。小扣出于美观考虑，希望最后二叉树上每个蓝色相连部分的结点个数不能超过 k 个，求所有染成蓝色的结点价值总和最大是多少？
示例 1：
输入：root = [5,2,3,4], k = 2
输出：12
解释：结点 5、3、4 染成蓝色，获得最大的价值 5+3+4=12
示例 2：
输入：root = [4,1,3,9,null,null,2], k = 2
输出：16
解释：结点 4、3、9 染成蓝色，获得最大的价值 4+3+9=16
提示：
1 <= k <= 10
1 <= val <= 10000
1 <= 结点数量 <= 10000
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

// f[i](0≤i≤k) 表示以该节点为根，相邻的子节点为 蓝色 的个数为 i 的情况下（包括自身），
// 节点价值总和的最大值；
