// ����һ����������������е�����k����㡣
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* slow = pListHead;
        ListNode* fast = slow;
        while (k--)
        {
            if (fast)
                fast = fast->next;
            else
                return NULL;
        }
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
