/*
��һ����СΪ n �� n Ϊ ż�� �������У����� 0 <= i <= (n / 2) - 1 �� i ���� i ���ڵ㣨�±�� 0 ��ʼ���������ڵ�Ϊ�� (n-1-i) ���ڵ� ��
�ȷ�˵��n = 4 ��ô�ڵ� 0 �ǽڵ� 3 �������ڵ㣬�ڵ� 1 �ǽڵ� 2 �������ڵ㡣���ǳ���Ϊ n = 4 �����������е������ڵ㡣
������ ����Ϊһ���ڵ���������ڵ�����ֵ֮�͡�
����һ������Ϊż���������ͷ�ڵ� head �����㷵������� ��������� ��
ʾ�� 1��
���룺head = [5,4,2,1]
�����6
���ͣ�
�ڵ� 0 �ͽڵ� 1 �ֱ��ǽڵ� 3 �� 2 �������ڵ㡣�����Ͷ�Ϊ 6 ��
������û�����������ڵ㡣
���ԣ����������������� 6 ��
ʾ�� 2��
���룺head = [4,2,2,3]
�����7
���ͣ�
�����е������ڵ�Ϊ��
- �ڵ� 0 �ǽڵ� 3 �������ڵ㣬������Ϊ 4 + 3 = 7 ��
- �ڵ� 1 �ǽڵ� 2 �������ڵ㣬������Ϊ 2 + 2 = 4 ��
���ԣ����������Ϊ max(7, 4) = 7 ��
ʾ�� 3��
���룺head = [1,100000]
�����100001
���ͣ�
������ֻ��һ�������ڵ㣬������Ϊ 1 + 100000 = 100001 ��
��ʾ��
����Ľڵ���Ŀ�� [2, 10^5] �е� ż�� ��
1 <= Node.val <= 10^5
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
    int pairSum(ListNode* head) {
        vector<int> v;
        while(head != nullptr)
        {
            v.push_back(head ->val);
            head = head->next;
        }
        int ret = 0;
        for (int i = 0; i < v.size() / 2; i++)
            ret = max(ret, v[i] + v[v.size() - 1 - i]);
        return ret;
    }
};
