// ����һ�������ж��������Ƿ��л��� 
// Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
// ��� pos �� -1�����ڸ�������û�л���
// ʾ�� 1��
// ���룺head = [3,2,0,-4], pos = 1
// �����true
// ���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
// ʾ�� 2��
// ���룺head = [1,2], pos = 0
// �����true
// ���ͣ���������һ��������β�����ӵ���һ���ڵ㡣
// ʾ�� 3��
// ���룺head = [1], pos = -1
// �����false
// ���ͣ�������û�л���
// ���ף�
// ������ O(1)�������������ڴ�����������

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

