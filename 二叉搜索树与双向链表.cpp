/*
����һ�ö��������������ö���������ת����һ�������ѭ��˫������Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��
Ϊ���������õ�������⣬������Ķ���������Ϊ����
����ϣ�����������������ת��Ϊ˫��ѭ�����������е�ÿ���ڵ㶼��һ��ǰ���ͺ��ָ�롣����˫��ѭ��������һ���ڵ��ǰ�������һ���ڵ㣬���һ���ڵ�ĺ���ǵ�һ���ڵ㡣
��ͼչʾ������Ķ���������ת���ɵ�������head�� ��ʾָ������������СԪ�صĽڵ㡣
�ر�أ�����ϣ�����Ծ͵����ת����������ת������Ժ����нڵ����ָ����Ҫָ��ǰ�������нڵ����ָ����Ҫָ���̡�����Ҫ���������еĵ�һ���ڵ��ָ�롣
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return nullptr;

        Node* head = nullptr;
        Node* prev = nullptr;
        _treeToDoublyList(root, head, prev);
        head->left = prev;
        prev->right = head;
        return head;
    }

    void _treeToDoublyList(Node* root, Node*& head, Node*& prev)
    {
        if (root == nullptr)
            return;
        
        _treeToDoublyList(root->left, head, prev);

        if (head == nullptr)
        {
            head = root;
            prev = root;
        }
        else
        {
            prev->right = root;
            root->left = prev;
            prev = root;
        }

        _treeToDoublyList(root->right, head, prev);
    }
};
