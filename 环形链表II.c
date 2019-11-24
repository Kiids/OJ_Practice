// ����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
// Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
// ��� pos �� -1�����ڸ�������û�л���
// ˵�����������޸ĸ���������
// ʾ�� 1��
// ���룺head = [3,2,0,-4], pos = 1
// �����tail connects to node index 1
// ���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
// ʾ�� 2��
// ���룺head = [1,2], pos = 0
// �����tail connects to node index 0
// ���ͣ���������һ��������β�����ӵ���һ���ڵ㡣
// ʾ�� 3��
// ���룺head = [1], pos = -1
// �����no cycle
// ���ͣ�������û�л���
// ���ף�
// ���Ƿ���Բ��ö���ռ������⣿

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    if (head == NULL || head->next == NULL)
        return NULL;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
            break;
    }
    if (slow != fast)
        return NULL;
    struct ListNode* cur = head;
    while (cur != slow)
    {
        cur = cur->next;
        slow = slow->next;
    }
    return cur;
}
