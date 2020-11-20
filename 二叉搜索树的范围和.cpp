/*
给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。
示例 1：
输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
输出：32
示例 2：
输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
输出：23
提示：
树中节点数目在范围 [1, 2 * 104] 内
1 <= Node.val <= 105
1 <= low <= high <= 105
所有 Node.val 互不相同
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return 0;
        if (root->val >= low && root->val <= high)
            return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) + root->val;
        else
            return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

// 前序遍历
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur || stk.size()) {
            while(cur) {
                stk.push(cur);
                if(cur->val >= L && cur->val <= R) res += cur->val;
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            cur = cur->right;
        }
        return res;
    }
};

// 中序遍历
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur || stk.size()) {
            while(cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if(cur->val >= L && cur->val <= R) res += cur->val;
            cur = cur->right;
        }
        return res;
    }
};

// 后序遍历
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur || stk.size()) {
            while(cur) {
                stk.push(cur);
                if(cur->val >= L && cur->val <= R) res += cur->val;
                cur = cur->right;
            }
            cur = stk.top();
            stk.pop();
            cur = cur->left;
        }
        return res;
    }
};

// 层序遍历
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        queue<TreeNode*> q;
        int res = 0;
        if(root) q.push(root);
        while(q.size()) {
            int n = q.size();
            for(int i = 0; i < n; i ++) {
                TreeNode* tr = q.front();
                q.pop();
                if(tr->val >= L && tr->val <= R) res += tr->val;
                if(tr->left) q.push(tr->left);
                if(tr->right) q.push(tr->right);
            }
        }
        return res;
    }
};
