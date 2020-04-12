/*
����һ����������������ڵ�ֵ�ľ���β�α����������ȴ������ң��ٴ������������һ��������Դ����ƣ������֮�佻����У���
���磺
����������?[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
���ؾ���β�α������£�

[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;

        if(root==NULL)
            return ret;
        
        int deep;
        q.push(root);
        deep = 1;

        vector<int> v;
        while (!q.empty())
        {
            int size = q.size();
            v.clear();
            while (size--)
            {
                TreeNode* front = q.front();
                q.pop();

                if (front->left)
                    q.push(front->left);

                if (front->right)
                    q.push(front->right);

                v.push_back(front->val);
            }
            
            if ((deep++) % 2 == 0)
                reverse(v.begin(), v.end());
                
            ret.push_back(v);
        }
        return ret;
    }
};
