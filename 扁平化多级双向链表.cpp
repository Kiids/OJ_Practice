/*
�༶˫�������У�����ָ����һ���ڵ��ǰһ���ڵ�ָ��֮�⣬������һ��������ָ�룬����ָ�򵥶���˫��������Щ���б�Ҳ���ܻ���һ�������Լ�������������ƣ����ɶ༶���ݽṹ���������ʾ����ʾ��
����λ���б��һ����ͷ�ڵ㣬�����ƽ���б�ʹ���н������ڵ���˫�����С�
ʾ�� 1��
���룺head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
�����[1,2,3,7,8,11,12,9,10,4,5,6]
���ͣ�
����Ķ༶�б�����ͼ��ʾ��
��ƽ�������������ͼ��
ʾ�� 2��
���룺head = [1,2,null,3]
�����[1,3,2]
���ͣ�
����Ķ༶�б�����ͼ��ʾ��
  1---2---NULL
  |
  3---NULL
ʾ�� 3��
���룺head = []
�����[]
��α�ʾ���������еĶ༶����
�� ʾ�� 1 Ϊ����
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
���л����е�ÿһ��֮��
[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
Ϊ�˽�ÿһ�������л���һ��������Ҫÿһ�������ֵΪ null ��Ԫ�أ��Ա�ʾû�нڵ����ӵ���һ�����ϼ��ڵ㡣
[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
�ϲ��������л��������ȥ��ĩβ�� null ��
[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
��ʾ��
�ڵ���Ŀ������ 1000
1 <= Node.val <= 10^5
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr)
            return head;
            
        Node* dummy = new Node(0);
        DFS(dummy, head);
        dummy->next->prev = nullptr;
        return dummy->next;
    }

    Node* DFS(Node* prev, Node* next)
    {
        if (next == nullptr)
            return prev;
            
        prev->next = next;
        next->prev = prev;

        Node* tempNext = next->next;
        Node* tail = DFS(next, next->child);
        next->child = nullptr;
        return DFS(tail, tempNext);
    }
};
