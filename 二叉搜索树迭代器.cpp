/*
ʵ��һ��������������������BSTIterator ����ʾһ�����������������������BST���ĵ�������
BSTIterator(TreeNode root) ��ʼ�� BSTIterator ���һ������BST �ĸ��ڵ� root ����Ϊ���캯����һ���ָ�����ָ��Ӧ��ʼ��Ϊһ���������� BST �е����֣��Ҹ�����С�� BST �е��κ�Ԫ�ء�
boolean hasNext() �����ָ���Ҳ�����������֣��򷵻� true �����򷵻� false ��
int next()��ָ�������ƶ���Ȼ�󷵻�ָ�봦�����֡�
ע�⣬ָ���ʼ��Ϊһ���������� BST �е����֣����Զ� next() ���״ε��ý����� BST �е���СԪ�ء�
����Լ��� next() ����������Ч�ģ�Ҳ����˵�������� next() ʱ��BST ��������������ٴ���һ����һ�����֡�
ʾ����
����
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
���
[null, 3, 7, true, 9, true, 15, true, 20, false]
����
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // ���� 3
bSTIterator.next();    // ���� 7
bSTIterator.hasNext(); // ���� True
bSTIterator.next();    // ���� 9
bSTIterator.hasNext(); // ���� True
bSTIterator.next();    // ���� 15
bSTIterator.hasNext(); // ���� True
bSTIterator.next();    // ���� 20
bSTIterator.hasNext(); // ���� False
��ʾ��
���нڵ����Ŀ�ڷ�Χ [1, 105] ��
0 <= Node.val <= 106
������ 105 �� hasNext �� next ����
���ף�
��������һ���������������Ľ��������next() �� hasNext() ������̯ʱ�临�Ӷ�Ϊ O(1) ����ʹ�� O(h) �ڴ档���� h �����ĸ߶ȡ�
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
class BSTIterator {
public:
    vector<TreeNode*> v;
    BSTIterator(TreeNode* root) {
        while (root)
        {
            v.push_back(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* cur = v.back();
        int val = cur->val;
        v.pop_back();

        cur  = cur->right;
        while (cur)
        {
            v.push_back(cur);
            cur = cur->left;
        }
        return val;
    }
    
    bool hasNext() {
        return !v.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
