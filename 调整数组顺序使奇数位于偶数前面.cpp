// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
// 所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
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
