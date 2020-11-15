/*
����һ������������ý�� head��������ÿ������ֵ���� 0 ���� 1����֪��������һ���������ֵĶ����Ʊ�ʾ��ʽ��
���㷵�ظ���������ʾ���ֵ� ʮ����ֵ ��
ʾ�� 1��
���룺head = [1,0,1]
�����5
���ͣ��������� (101) ת��Ϊʮ������ (5)
ʾ�� 2��
���룺head = [0]
�����0
ʾ�� 3��
���룺head = [1]
�����1
ʾ�� 4��
���룺head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
�����18880
ʾ�� 5��
���룺head = [0,0]
�����0
��ʾ��
����Ϊ�ա�
����Ľ������������ 30��
ÿ������ֵ���� 0 ���� 1��
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ret = 0;
        while (head)
        {
            ret = ret * 2 + head->val;
            head = head->next;
        }
        return ret;
    }
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ret = 0;
        while (head)
        {
            ret = (ret << 1) + head->val;
            head = head->next;
        }
        return ret;
    }
};
//˼·��ÿ������1λ
//1.res = (res << 1) + head->val;
//2.res = (res << 1) ^ head->val;
//3.res = (res << 1) | head->val;
