/*
����һ��������������Ķ�������
root.val == 0
��� treeNode.val == x �� treeNode.left != null����ô treeNode.left.val == 2 * x + 1
��� treeNode.val == x �� treeNode.right != null����ô treeNode.right.val == 2 * x + 2
��������������ܵ�����Ⱦ�������е� treeNode.val ������� -1��
�����Ȼ�ԭ��������Ȼ��ʵ�� FindElements �ࣺ
FindElements(TreeNode* root) ������Ⱦ�Ķ�������ʼ����������Ҫ�Ȱ�����ԭ��
bool find(int target) �ж�Ŀ��ֵ target �Ƿ�����ڻ�ԭ��Ķ������в����ؽ����
ʾ�� 1��
���룺
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
�����
[null,false,true]
���ͣ�
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True 
ʾ�� 2��
���룺
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
�����
[null,true,true,false]
���ͣ�
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
ʾ�� 3��
���룺
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
�����
[null,true,false,false,true]
���ͣ�
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
��ʾ��
TreeNode.val == -1
�������ĸ߶Ȳ����� 20
�ڵ�������� [1, 10^4] ֮��
���� find() ���ܴ����� [1, 10^4] ֮��
0 <= target <= 10^6
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
class FindElements {
    unordered_set<int> s;
    void DFS(TreeNode* cur, int val)
    {
        if (cur != nullptr)
        {
            cur->val = val;
            s.insert(val);
            DFS(cur->left, 2 * val + 1);
            DFS(cur->right, 2 * val + 2);
        }
    }
public:
    FindElements(TreeNode* root) {
        DFS(root, 0);
    }
    
    bool find(int target) {
        return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
