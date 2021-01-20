/*
������������ list1 �� list2 �����ǰ�����Ԫ�طֱ�Ϊ n ���� m ����
���㽫 list1 �е� a ���ڵ㵽�� b ���ڵ�ɾ��������list2 ���ڱ�ɾ���ڵ��λ�á�
��ͼ����ɫ�ߺͽڵ�չʾ�˲�����Ľ����
���㷵�ؽ�������ͷָ�롣
ʾ�� 1��
���룺list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
�����[0,1,2,1000000,1000001,1000002,5]
���ͣ�����ɾ�� list1 �е����͵��ĸ��ڵ㣬���� list2 ���ڸ�λ�á���ͼ����ɫ�ıߺͽڵ�Ϊ������
ʾ�� 2��
���룺list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
�����[0,1,1000000,1000001,1000002,1000003,1000004,6]
���ͣ���ͼ����ɫ�ıߺͽڵ�Ϊ������
��ʾ��
3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* end2 = list2;
        while (end2->next)
            end2 = end2->next;
        ListNode *pre = list1, *cur = list1->next;
        int n = 1;
        while (n <= b)
        {
            if (n == a)
                pre->next = list2;
            if (n > a)
                delete(pre);
            pre = cur;
            cur = cur->next;
            n++;
        }
        end2->next = cur;
        pre->next = nullptr;
        return list1;
    }
};
