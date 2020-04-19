/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
示例：
输入：nums =?[1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
提示：
1 <= nums.length <= 50000
1 <= nums[i] <= 10000
*/
// 首尾双指针
//定义头指针 leftleft ，尾指针 rightright .
//leftleft 一直往右移，直到它指向的值为偶数
//rightright 一直往左移， 直到它指向的值为奇数
//交换 nums[left]nums[left] 和 nums[right]nums[right] .
//重复上述操作，直到 left == rightleft==right .
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if ((nums[left] & 1) != 0)
            {
                left++;
                continue;
            }
            if ((nums[right] & 1) != 1)
            {
                right--;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};

// 快慢双指针
//定义快慢双指针 fastfast 和 lowlow ，fastfast 在前， lowlow 在后 .
//fastfast 的作用是向前搜索奇数位置，lowlow 的作用是指向下一个奇数应当存放的位置
//fastfast 向前移动，当它搜索到奇数时，将它和 nums[low]nums[low] 交换，此时 lowlow 向前移动一个位置 .
//重复上述操作，直到 fastfast 指向数组末尾 .
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low = 0, fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] & 1)
            {
                swap(nums[low], nums[fast]);
                low++;
            }
            fast++;
        }
        return nums;
    }
}; 

// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
// 所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

// 以下方法在LeetCode中会出现超时现象 
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        int even = 0;
        int odd = 0;
         
        while (even < len)
        {
            if (array[even] % 2 != 0)
            {
                int tmp = array[even];
                for (int i = even; i > odd; i--)
                    array[i] = array[i-1];
                 
                array[odd] = tmp;
                even++;
                odd++;
            }
            else
                even++;
        }
    }
};
 
//用两个下标odd,even,even遍历数组，遇到偶数继续往后走，遇到奇数就将该奇数赋给odd对应位置，
//然后odd往后移动（先将从odd开始的位置的所有元素往后挪动一个，这样做的目的是能够保持偶数相对位置不变）。
//这个思路也就是使得odd前面的都是奇数，而且相对位置不变，而odd与even之间的都是偶数，然后even遇到奇数停下来，
//并将其放到odd位置，并且前提是将odd位置上的偶数向后挪动保证偶数相对位置不变，这样当even走到最后时，
//就使得odd之前的都是奇数，odd与even之间的都是偶数。

