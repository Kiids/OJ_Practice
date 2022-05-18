/*
��ȫ������ ��ÿһ�㣨�����һ���⣩������ȫ��䣨�����ڵ����ﵽ��󣩵ģ��������еĽڵ㶼�����ܵؼ�������ࡣ
���һ���㷨����һ���½ڵ���뵽һ�������Ķ������У����ڲ���󱣳���������
ʵ�� CBTInserter ��:
CBTInserter(TreeNode root) ʹ��ͷ�ڵ�Ϊ root �ĸ�������ʼ�������ݽṹ��
CBTInserter.insert(int v)  �����в���һ��ֵΪ Node.val == val���½ڵ� TreeNode��ʹ��������ȫ��������״̬�������ز���ڵ� TreeNode �ĸ��ڵ��ֵ��
CBTInserter.get_root() ����������ͷ�ڵ㡣
ʾ�� 1��
����
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
���
[null, 1, 2, [1, 2, 3, 4]]
����
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // ���� 1
cBTInserter.insert(4);  // ���� 2
cBTInserter.get_root(); // ���� [1, 2, 3, 4]
��ʾ��
���нڵ�������ΧΪ [1, 1000] 
0 <= Node.val <= 5000
root ����ȫ������
0 <= val <= 5000 
ÿ���������������� insert �� get_root ���� 10^4 ��
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
class CBTInserter {
    TreeNode* root;
    queue<TreeNode*> q;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        q.push(root);
        // ֻҪ��ǰ�ڵ���������ӽڵ㣬���������ģ��������ӽڵ���ջ
        // ֱ������һ���ӽڵ㲻���Ľڵ�Ϊֹ����ʱ�˳�ѭ����������Ҫ�ҵĸ��ڵ�
        while (q.front()->left != nullptr && q.front()->right != nullptr)
        {
            auto tmp = q.front();
            q.pop();
            q.push(tmp->left);
            q.push(tmp->right);
        }
    }
    
    int insert(int val) {
        TreeNode* parent = q.front();        // ȡ���׽ڵ㣬�����ӽڵ㲻��
        TreeNode* node = new TreeNode(val);
        if (parent->left == nullptr)         // ��û�����ӽڵ㣬ֱ�ӹҵ����
            parent->left = node;
        else                                 // ��û�����ӽڵ㣬ֱ�ӹҵ��ұ�
        {
            parent->right = node;
            q.pop();                         // ��ʱ�ýڵ�����������
            q.push(parent->left);            // ���������ӽڵ�������
            q.push(parent->right);
        }

        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
 
 // ��������ҵ����һ��Ӧ�ò���Ľڵ�λ�õĸ��ڵ�
 
