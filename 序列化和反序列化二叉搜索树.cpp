/*
���л��ǽ����ݽṹ�����ת��Ϊһϵ��λ�Ĺ��̣��Ա������Դ洢���ļ����ڴ滺�����У���ͨ������������·���䣬�Ա��Ժ���ͬһ������һ��������������ؽ���
���һ���㷨�����л��ͷ����л� ���������� �� �����л�/�����л��㷨�Ĺ�����ʽû�����ơ� ��ֻ��ȷ�������������������л�Ϊ�ַ��������ҿ��Խ����ַ��������л�Ϊ����Ķ�����������
������ַ���Ӧ�����ܽ��ա�
ʾ�� 1��
���룺root = [2,1,3]
�����[2,1,3]
ʾ�� 2��
���룺root = []
�����[]
��ʾ��
���нڵ�����Χ�� [0, 104]
0 <= Node.val <= 104
��Ŀ���� ��֤ ���������һ�ö�����������
ע�⣺��Ҫʹ�����Ա/ȫ��/��̬�������洢״̬�� ������л��ͷ����л��㷨Ӧ������״̬�ġ�
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "#";
        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return rebuildTree(ss);
    }

    TreeNode* rebuildTree(stringstream &ss){
        string tmp;
        ss >> tmp;
        if (tmp == "#")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(tmp));
        node->left = rebuildTree(ss);
        node->right = rebuildTree(ss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
