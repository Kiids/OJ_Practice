/*
��дһ���������������������Ƿ��ǻ��ĵġ�
ʾ�� 1��
���룺 1->2
����� false 
ʾ�� 2��
���룺 1->2->2->1
����� true 
���ף�
���ܷ��� O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿
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
