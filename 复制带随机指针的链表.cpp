// 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
// 要求返回这个链表的深拷贝。
// 示例：
// 输入：
// {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
// 解释：
// 节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
// 节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
// 提示：
// 你必须返回给定头的拷贝作为对克隆列表的引用。

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
        // 复制节点
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
        // 复制节点的random指针
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
        // 拆解重组复制的链表
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

