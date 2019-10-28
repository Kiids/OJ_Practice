// ����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
// ����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
// ����������
// 1->2->2->1
// ���أ�true
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* newhead = NULL;
        ListNode* cur = head;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;
    }
    bool chkPalindrome(ListNode* A) {
        // write code here
        int n = 0;
        ListNode* cur = A;
        while (cur)
        {
            cur = cur->next;
            n++;
        }
        cur = A;
        int mid = n/2;
        while (mid--)
            cur = cur->next;
        ListNode* head1 = A;
        ListNode* head2 = reverseList(cur);
        mid = n/2;
        while (mid--)
        {
            if (head1->val == head2->val)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            else
                return false;
        }
        return true;
    }
};

