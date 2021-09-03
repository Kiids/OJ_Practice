/*
�������� �ǿ� ���������������Ǹ��������������λλ������ʼλ�á����ǵ�ÿ���ڵ�ֻ�洢һλ���֡�����������ӻ᷵��һ���µ�����
����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��
ʾ��1��
���룺l1 = [7,2,4,3], l2 = [5,6,4]
�����[7,8,0,7]
ʾ��2��
���룺l1 = [2,4,3], l2 = [5,6,4]
�����[8,0,7]
ʾ��3��
���룺l1 = [0], l2 = [0]
�����[0]
��ʾ��
����ĳ��ȷ�ΧΪ [1, 100]
0 <= node.val <= 9
�������ݱ�֤��������������ǰ�� 0
���ף���������������޸ĸ���δ������仰˵�����ܶ��б��еĽڵ���з�ת��
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a, b;
        int sub = 0;
        while (l1)
        {
            a.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            b.push(l2->val);
            l2 = l2->next;
        }
        auto pre = l1 = nullptr, head = pre;
        while (a.size() || b.size() || sub) 
        {
            if (a.size())
            {
                sub += a.top();
                a.pop();
            }
            if (b.size())
            {
                sub += b.top();
                b.pop();
            }
            pre = new ListNode(sub % 10);
            sub = sub / 10;
            pre->next = head;
            head = pre;
        }
        return head;
    }
};
