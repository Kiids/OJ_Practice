/*
��������ͷ��� head���������ϵ�ÿ����㶼��һ�� Ψһ������ֵ ��
ͬʱ�����б� G�����б�����������������ֵ��һ���Ӽ���
�����б� G ������ĸ��������������Ķ���Ϊ��������һ�����������ֵ����ֵ�������б� G �У����ɵļ��ϡ�
ʾ�� 1��
����: 
head: 0->1->2->3
G = [0, 1, 3]
���: 2
����: 
������,0 �� 1 �������ӵģ��� G �в����� 2������ [0, 1] �� G ��һ�������ͬ�� [3] Ҳ��һ��������ʷ��� 2��
ʾ�� 2��
����: 
head: 0->1->2->3->4
G = [0, 3, 1, 4]
���: 2
����: 
�����У�0 �� 1 �������ӵģ�3 �� 4 �������ӵģ����� [0, 1] �� [3, 4] ������������ʷ��� 2��
��ʾ��
��� N �Ǹ������� head �ĳ��ȣ�1 <= N <= 10000��
������ÿ������ֵ���ڷ�ΧΪ [0, N - 1]��
1 <= G.length <= 10000
G �����������н���ֵ��һ���Ӽ�.
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
    int numComponents(ListNode* head, vector<int>& nums) {
        bool exists[10000];
        memset(exists, 0, sizeof(exists));
        for (int e : nums)
            exists[e] = true;
        int ret = 0;
        ListNode* curr = head;
        while (curr != nullptr)
        {
            if (exists[curr->val] && (curr->next == nullptr || !exists[curr->next->val]))
                ret++;
            curr = curr->next;
        }
        return ret;
    }
};
