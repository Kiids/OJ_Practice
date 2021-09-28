/*
����һ��������
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
���룺root = [1,2,3,4,5,null,7]
�����[1,#,2,3,#,4,5,7,#]
���ͣ�������������ͼ A ��ʾ����ĺ���Ӧ���������ÿ�� next ָ�룬��ָ������һ���Ҳ�ڵ㣬��ͼ B ��ʾ�����л�������������˳���� next ָ�����ӣ���'#' ��ʾÿ���ĩβ��
��ʾ��
���еĽڵ���С�� 6000
-100 <= node.val <= 100
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
        if (!root)
            return nullptr;
        queue<Node*> q;
        Node* cur = root;
        q.push(root);
        int n = 1;
        while (!q.empty())
        {
            q.pop();
            n--;
            if (cur->left) 
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
            if (n == 0)
            {
                cur->next = nullptr;
                n = q.size();
            }
            else
                cur->next = q.front();
            cur = q.front();
        }
        return root;
    }
};
