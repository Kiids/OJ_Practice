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
// 当前节点为空时，f[i]=0，0≤i≤k；
// 当 i=0 时，即表示当前节点为白色，此时无所谓相邻子节点什么颜色，
// 所以当前节点为根价值总和的最大值为 左子节点所有情况 和 右子节点所有情况 的最大值，
// 即 f[0]=max(fl)+max(fr)；
// 当 i=1 时，即表示当前节点为蓝色，且除自身外相邻的子节点为蓝色的个数为 0，
// 所以当前节点为根价值总和的最大值为 左子节点为白色 和 右子节点为白色 的最大值 加上自身的值，
// 即 f[1]=root.val+fl[0]+fr[0]；
// 当 i=2 时，即表示当前节点为蓝色，且除自身外相邻的子节点为蓝色的个数为 1，
// 所以当前节点为根价值总和的最大值可分多种情况，即蓝色节点在左边和在右边的情况；
// 故，f[0]=max(fl)+max(fr)，i=0
// f[i]=max(val+fl[j]+fr[i-j-1])，0<i≤k,0<j<i

// 状态定义： 定义 dp[i] 为当该节点相连的 i 个节点（包括其自身）都被染成蓝色的最大价值。
// 转移方程：当 i==0 的时候， dp[0]=max(dpl)+max(dpr), 也就是左右节点dp最大值相加。
// 当 i>0 的时候，通过遍历左右节点的所有情况来取得最大值，
// 所以有 dp[i]=max(dp[i],dpl[j]+dpr[i-j-1],其中 j<i,1<=i<=k, 取最大即可。
// 初始值：当遍历到空节点的时候， 直接返回一个 值全为 0 的 dp 数组。

