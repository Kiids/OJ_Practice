/*
����һ�����������ѡ�������һ���ڵ㣬��������Ӧ�Ľڵ�ֵ����֤ÿ���ڵ㱻ѡ�ĸ���һ����
����:
�������ʮ�ִ��ҳ���δ֪����ν��������⣿���ܷ�ʹ�ó������ռ临�Ӷ�ʵ�֣�
ʾ��:
// ��ʼ��һ�������� [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);
// getRandom()����Ӧ�������1,2,3�е�һ������֤ÿ��Ԫ�ر����صĸ�����ȡ�
solution.getRandom();
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
    ListNode* head;
    Solution(ListNode* head) : head(head) {

    }
    
    int getRandom() {
        int ret = head->val;
        ListNode* cur = head->next;
        int k = 2;
        while (cur != nullptr)
        {
            if ((rand() % k) == 0)  // ģ�����1/k
                ret = cur->val;
            k++;
            cur = cur->next;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
