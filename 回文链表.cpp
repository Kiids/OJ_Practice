/*
编写一个函数，检查输入的链表是否是回文的。
示例 1：
输入： 1->2
输出： false 
示例 2：
输入： 1->2->2->1
输出： true 
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* pre = head;
        ListNode* slow = pre->next;
        ListNode* fast = slow->next;
        
        while (fast != nullptr && fast->next != nullptr)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (pre != nullptr)
            pre->next = nullptr;

        pre = nullptr;
        while (slow != nullptr)
        {
            ListNode* tempNode = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tempNode;
        }

        while (pre != nullptr && head != nullptr)
        {
            if (pre->val != head->val)
                return false;
            pre = pre->next;
            head = head->next;
        }
        return true;  
    }
};

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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *p = head;
        while (p)
        {
            s.push(p->val);
            p = p->next;
        }
        p = head;
        while (p)
        {
            if (p->val != s.top())
                return false;
            s.pop();
            p = p->next;
        }
        return true;
    }
};
