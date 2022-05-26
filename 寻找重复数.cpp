/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。
你设计的解决方案必须不修改数组 nums 且只用常量级 O(1) 的额外空间。
示例 1：
输入：nums = [1,3,4,2,2]
输出：2
示例 2：
输入：nums = [3,1,3,4,2]
输出：3
示例 3：
输入：nums = [1,1]
输出：1
示例 4：
输入：nums = [1,1,2]
输出：1
提示：
1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
进阶：
如何证明 nums 中至少存在一个重复的数字?
你可以设计一个线性级时间复杂度 O(n) 的解决方案吗？
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while (true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow)
                break;
        }
        int x = 0;
        while (true)
        {
            x = nums[x];
            slow = nums[slow];
            if (slow == x)
                break;        
        }
        return slow;
    }
};

//数组形式的链表
//题目设定的问题是 N+1 个元素都在 [1,n] 这个范围内。将这个题数组当作一个链表，数组的下标就是指向元素的指针，
//把数组的元素也看作指针。如 0 是指针，指向 nums[0]，而 nums[0] 也是指针，指向 nums[nums[0]].
//链表中的环
//例：[1,2,3,4,5,6,7,8,9,5]。按照循环
//int point = 0;
//while(true)
//    point = nums[point]; // 等同于 next = next->next; 
//得到路径: 1 2 3 4 5 [6 7 8 9] [6 7 8 9] [6 7 8 9] . 就有了一个环，6 7 8 9。point 在环中循环前进。
//起点到环的入口长度m，环周长为c，在fast和slow相遇时slow走了n步。则fast走了2n步，fast比slow多走了n步，
//这n步全用在了在环里循环（n%c==0）。当fast和last相遇之后，设置第三个指针finder，它
//从起点开始和slow(在fast和slow相遇处)同步前进，当finder和slow相遇时，就是在环的入口处相遇，也就是重复的那个数字。
//fast 和 slow 相遇时，slow 在环中行进的距离是n-m，其中 n%c==0。让 slow 前进 m 步——也就是在环中走了 n 步了。
//而 n%c==0 即 slow 在环里面走的距离是环的周长的整数倍，就回到了环的入口重复数字。

