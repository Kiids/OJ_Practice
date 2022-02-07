/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
示例 3：
输入：head = []
输出：[]
提示：
链表中节点的数目在范围 [0, 5 * 10^4] 内
-10^5 <= Node.val <= 10^5
进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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
    //快慢指针分割链表
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

    // 非递归归并
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

// 归并排序nlogn
// 1.先拆开：fast-slow法，双指针，一个每次走两步，一个走一步，
// 2.再合并：将两段的头结点值进行比较

