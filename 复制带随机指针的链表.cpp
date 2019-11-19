// ����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
// Ҫ�󷵻��������������
// ʾ����
// ���룺
// {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
// ���ͣ�
// �ڵ� 1 ��ֵ�� 1��������һ��ָ������ָ�붼ָ��ڵ� 2 ��
// �ڵ� 2 ��ֵ�� 2��������һ��ָ��ָ�� null�����ָ��ָ�����Լ���
// ��ʾ��
// ����뷵�ظ���ͷ�Ŀ�����Ϊ�Կ�¡�б�����á�

/* 
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // ���ƽڵ�
        Node* cur = head;
        while (cur)
        {
            Node* next = cur->next;
            Node* cpnode = (Node*)malloc(sizeof(Node));
            cpnode->val = cur->val;
            cpnode->next = next;
            cur->next = cpnode;
            
            cur = next;
        }
        // ���ƽڵ��randomָ��
        cur = head;
        while (cur)
        {
            Node* cpnode = cur->next;
            if (cur->random)
                cpnode->random = cur->random->next;
            else
                cpnode->random = NULL;
            cur = cpnode->next;
        }
        // ������鸴�Ƶ�����
        Node *newhead = NULL, *newtail = NULL;
        cur = head;
        while (cur)
        {
            Node* cpnode = cur->next;
            Node* next = cpnode->next;
            if (newtail == NULL)
                newhead = newtail = cpnode;
            else
            {
                newtail->next = cpnode;
                newtail = newtail->next;
            }
            cur->next = next;
            cur = next;
        }
        return newhead;
    }
};

