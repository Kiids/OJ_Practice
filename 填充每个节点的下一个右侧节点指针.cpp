/*
����һ�� ���������� ��������Ҷ�ӽڵ㶼��ͬһ�㣬ÿ�����ڵ㶼�������ӽڵ㡣�������������£�
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL��
��ʼ״̬�£����� next ָ�붼������Ϊ NULL��
���ף�
��ֻ��ʹ�ó���������ռ䡣
ʹ�õݹ����Ҳ����Ҫ�󣬱����еݹ����ռ�õ�ջ�ռ䲻��������Ŀռ临�Ӷȡ�
ʾ����
���룺root = [1,2,3,4,5,6,7]
�����[1,#,2,3,#,4,5,6,7,#]
���ͣ�������������ͼ A ��ʾ����ĺ���Ӧ���������ÿ�� next ָ�룬��ָ������һ���Ҳ�ڵ㣬��ͼ B ��ʾ�����л������������������У�ͬһ��ڵ��� next ָ�����ӣ�'#' ��־��ÿһ��Ľ�����
��ʾ��
���нڵ���������� 4096
-1000 <= node.val <= 1000
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        auto pre = root;
        while (pre->left)
        {
            auto cur = pre;
            while (cur)
            {
                cur->left->next = cur->right;
                if (cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
        return root;
    }
};
