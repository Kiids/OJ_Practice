/*
���������ͷ��� head ���뽫�䰴 ���� ���в����� ���������� ��
ʾ�� 1��
���룺head = [4,2,1,3]
�����[1,2,3,4]
ʾ�� 2��
���룺head = [-1,5,3,4,0]
�����[-1,0,3,4,5]
ʾ�� 3��
���룺head = []
�����[]
��ʾ��
�����нڵ����Ŀ�ڷ�Χ [0, 5 * 10^4] ��
-10^5 <= Node.val <= 10^5
���ף�������� O(n log n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£����������������
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
    //����ָ��ָ�����
    ListNode* mergeSort(ListNode*& head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL; 
        ListNode *L = mergeSort(head);
        ListNode *R = mergeSort(slow);
        return merge(L, R);
    }

    // �ǵݹ�鲢
    ListNode* merge(ListNode* L, ListNode* R)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (L != NULL && R != NULL)
        {
            if (L->val <= R->val)
            {
                cur->next = L;
                L = L->next;
                cur = cur->next; 
            }
            else
            {
                cur->next = R;
                R = R->next;
                cur = cur->next;
            }
        }
        
        if (L == NULL)
            cur->next = R;
        if (R == NULL)
            cur->next = L;
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};

// �鲢����nlogn
// 1.�Ȳ𿪣�fast-slow����˫ָ�룬һ��ÿ����������һ����һ����
// 2.�ٺϲ��������ε�ͷ���ֵ���бȽ�

