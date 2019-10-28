// 对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
// 给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
// 测试样例：
// 1->2->2->1
// 返回：true
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

